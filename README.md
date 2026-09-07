# Unreal Engine Workshop Template

## What Is This Project?

A tiny Third Person game for three workshops:

- collect three objects;
- see the total on a HUD;
- watch an AI guard patrol.

```plaintext
Make one small change -> Build or Compile -> Press Play -> See the result
```

## Getting Started

Git LFS is required for Unreal assets.

```plaintext
git lfs install
git clone <repository-url>
cd UEIntro_Dev_26
git lfs pull
```

1. Open `UEIntro_Dev_26.uproject`.
2. In Unreal, choose **Tools > Open IDE**.
3. Build `UEIntro_Dev_26Editor` if nessesarry.
4. Return to Unreal and press **Play**.


## Workshop 1 — Unreal C++

1. Open `Collectible.h` in Rider.
2. Add this below `Value`:

   ```cpp
   UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
   bool bRare = false;
   ```

3. Save and build.
4. Return to Unreal and open `BP_Collectible`.
5. Find the new **Rare** checkbox in Class Defaults.
6. Give different collectible instances different values.
7. Press Play.

You have connected C++ to the Unreal Editor.

## Workshop 2 — UI

1. Open `WBP_HUD`.
2. Select `ItemsText`.
3. Change its size, alignment, and colour.
4. Try placing it in a different layout container.
5. Add Text saying `Collect all 3 items!`.
6. Compile, save, and press Play.

## Workshop 3 — Behaviour Trees

1. Play and watch the guard.
2. Open `BT_Guard`.
3. Change **Wait** from `2.0` to `5.0` seconds.
4. Play again.
5. Keep the tree open during Play and watch the active nodes light up.

## Quick Cheatsheet

```plaintext
AActor        An object in the world.
APawn         An Actor that can be controlled.
ACharacter    A Pawn with character movement.
AAIController A controller for AI characters.
```

```cpp
UCLASS()                       // Unreal knows about this class
UPROPERTY(EditAnywhere)       // Editable in Unreal
UPROPERTY(BlueprintReadOnly)  // Blueprint can read it
UPROPERTY(BlueprintReadWrite) // Blueprint can read and change it
UFUNCTION(BlueprintCallable)  // Blueprint can call it

UE_LOG(LogTemp, Display, TEXT("Hello"));
```

```plaintext
int32 whole number       float decimal number
bool true/false          FText text shown to players
FString text used in code
FVector position         FRotator rotation
```

Behaviour Trees use **Tasks** for actions, a **Sequence** for ordered steps, a **Selector** for choices, **Decorators** for conditions, and a **Blackboard** for stored information.

Press **P** in the level viewport to show the green NavMesh.
