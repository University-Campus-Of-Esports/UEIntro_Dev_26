# Project Overview

## The game

You control `BP_ThirdPersonCharacter`, collect three `BP_Collectible` objects, read the total on `WBP_HUD`, and watch `BP_Guard` patrol.

```plaintext
Player
  |
  +-- WorkshopCharacter
  |       |
  |       +-- stores the collectible count
  |
  +-- WBP_HUD
          |
          +-- displays the count
```

## Collecting an object

```plaintext
BP_Collectible
      |
      v overlap
WorkshopCharacter
      |
      v
CollectedCollectibles++
```

`ACollectible` handles the overlap in C++. Its Blueprint supplies the visible mesh and editable settings.

## The guard

```plaintext
BP_Guard
    |
    v controlled by
BP_GuardController
    |
    v runs
BT_Guard
    |
    v uses
BB_Guard
```

The Behaviour Tree chooses a place, moves there, waits, and repeats.

## Why use both?

C++ holds the simple game rules. Blueprint handles things that are easier to see and change, such as the HUD, guard, and level.

```plaintext
C++ property -> build -> appears in Unreal
UI change    -> compile -> looks different
AI change    -> play -> behaves differently
```

The normal Third Person movement and camera code is unchanged. Extra sample variants were removed so the project stays focused.
