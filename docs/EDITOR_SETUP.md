# Instructor Editor Setup

This page is for the instructor. Complete it once, test the game, then commit the Unreal assets with Git LFS. Students should receive a finished project.

Do not make empty `.uasset` or `.umap` files by hand.

## 1. Start the project

1. Build `UEIntro_Dev_26Editor` in Rider.
2. Open the project in Unreal.
3. Create:

   ```plaintext
   Content/Workshop/
   |-- AI/
   |-- Blueprints/
   |-- Maps/
   `-- UI/
   ```

4. Open `BP_ThirdPersonCharacter`.
5. In **Class Settings**, check its parent is `WorkshopCharacter`.
6. If it is not, use **File > Reparent Blueprint** and choose `WorkshopCharacter`.
7. In Class Defaults, check `Required Collectibles = 3`.

Do not change the normal input, movement, camera, or animation setup.

## 2. Make `BP_Collectible`

1. In `Workshop/Blueprints`, make a Blueprint based on the C++ class `Collectible`.
2. Name it `BP_Collectible`.
3. Select its inherited **Mesh** component.
4. Set Static Mesh to `/Engine/BasicShapes/Sphere`.
5. In Class Defaults set:

   ```plaintext
   Display Name = Collectible
   Value = 1
   ```

6. Compile and save. It needs no Blueprint nodes.

## 3. Make `WBP_HUD`

1. In `Workshop/UI`, create a Widget Blueprint called `WBP_HUD`.
2. Make this hierarchy:

   ```plaintext
   Canvas Panel
   `-- HUDBorder
       `-- HUDVerticalBox
           |-- ItemsText
           `-- ItemsProgressBar
   ```

3. Set `HUDBorder` to the top-left anchor, position `(32, 32)`, size `(300, 90)`, and padding `12`.
4. Give it a dark, partly transparent colour.
5. Set `ItemsText` to `Items: 0 / 3`.
6. Set `ItemsProgressBar` to `0.0`.

Bind `ItemsText.Text`:

```plaintext
Get Player Character
  -> Cast To WorkshopCharacter
  -> get CollectedCollectibles and RequiredCollectibles
  -> Format Text "Items: {Collected} / {Required}"
  -> Return
```

Return `Items: 0 / 3` if the Cast fails.

Bind `ItemsProgressBar.Percent`:

```plaintext
Get Player Character
  -> Cast To WorkshopCharacter
  -> Get Collectible Progress
  -> Return
```

Return `0.0` if the Cast fails. Compile and save.

## 4. Make the AI assets

Create `BB_Guard` in `Workshop/AI`. Add one key:

```plaintext
TargetLocation : Vector
```

Create `BTT_FindRandomLocation` based on `BTTask_BlueprintBase`. Add two **Instance Editable** variables:

```plaintext
TargetLocationKey : Blackboard Key Selector
PatrolRadius      : Float = 600.0
```

Build this Event Graph:

```plaintext
Event Receive Execute AI
  -> Get Actor Location from Controlled Pawn
  -> Get Random Reachable Point in Radius
       Origin = Actor Location
       Radius = PatrolRadius
  -> Branch using Return Value

True:
  Set Blackboard Value as Vector
       Key = TargetLocationKey
       Value = Random Location
  -> Finish Execute, Success = true

False:
  Finish Execute, Success = false
```

Compile and save.

Create `BT_Guard` and choose `BB_Guard` as its Blackboard:

```plaintext
Root
`-- Sequence
    |-- BTT_FindRandomLocation
    |-- Move To
    `-- Wait
```

Set:

```plaintext
Find Random Location:
  Target Location Key = TargetLocation
  Patrol Radius = 600.0

Move To:
  Blackboard Key = TargetLocation

Wait:
  Wait Time = 2.0
  Random Deviation = 0.0
```

Create `BP_GuardController` based on `AIController`:

```plaintext
Event BeginPlay -> Run Behavior Tree (BT_Guard)
```

Create `BP_Guard` based on `Character`. Set:

```plaintext
AI Controller Class = BP_GuardController
Auto Possess AI = Placed in World or Spawned
Use Controller Rotation Yaw = false

Character Movement:
  Max Walk Speed = 250
  Orient Rotation to Movement = true
  Rotation Rate Z = 500

Mesh:
  Skeletal Mesh = SKM_Quinn_Simple
  Location Z = -89
  Rotation Z = -90
  Animation Mode = Use Animation Blueprint
  Anim Class = ABP_Unarmed
```

Compile and save both Blueprints.

## 5. Make `WorkshopMap`

1. Create a **Basic** level and save it as `Workshop/Maps/WorkshopMap`.
2. Keep a Directional Light, Sky Light, Sky Atmosphere, and Player Start.
3. Use Engine cubes for a floor and four walls:

   | Actor | Location | Scale |
   |---|---|---|
   | Floor | `(0, 0, -50)` | `(12, 12, 1)` |
   | NorthWall | `(0, 600, 75)` | `(12, .25, 1.5)` |
   | SouthWall | `(0, -600, 75)` | `(12, .25, 1.5)` |
   | EastWall | `(600, 0, 75)` | `(.25, 12, 1.5)` |
   | WestWall | `(-600, 0, 75)` | `(.25, 12, 1.5)` |

4. Put Player Start at `(0, 0, 100)`.
5. Add three collectibles:

   ```plaintext
   (250, 0, 60)      Display Name = First Item
   (-250, 200, 60)   Display Name = Second Item
   (0, -300, 60)     Display Name = Third Item
   ```

6. Add one `BP_Guard` at `(300, 300, 100)`.
7. Add a Nav Mesh Bounds Volume around the floor, about `1400 x 1400 x 400`.
8. Press **P**. The patrol floor must be green.

Open the Level Blueprint:

```plaintext
Event BeginPlay
  -> Get Player Controller
  -> Create Widget (Class = WBP_HUD)
  -> Add to Viewport
```

Set the Create Widget **Owning Player** to the Player Controller.

In **Project Settings > Maps & Modes**, set:

```plaintext
Editor Startup Map = WorkshopMap
Game Default Map = WorkshopMap
Default GameMode = BP_ThirdPersonGameMode
```

Check `BP_ThirdPersonGameMode` uses:

```plaintext
Default Pawn Class = BP_ThirdPersonCharacter
Player Controller Class = BP_ThirdPersonPlayerController
```

Save all.

## 6. Test

Press Play and check:

- movement and jumping still work;
- the HUD starts at `Items: 0 / 3`;
- all three items disappear and the HUD reaches `3 / 3`;
- the Output Log shows each collectible name;
- the guard walks, waits two seconds, and repeats;
- the Behaviour Tree lights up during Play;
- pressing **P** shows a green NavMesh.

Finally, build once more in Rider.

## 7. Git LFS

```plaintext
git lfs install
git check-attr filter -- Content/Workshop/AI/BT_Guard.uasset
git check-attr filter -- Content/Workshop/Maps/WorkshopMap.umap
git add .gitattributes Config Content/Workshop Source README.md docs
git lfs status
```

Both checks should say `lfs`. Do not add generated folders such as `Binaries`, `Intermediate`, `Saved`, or `.idea`.
