# C++ Guide

You do not need to understand all of C++ today. Focus on making one property appear in Unreal.

## `.h` and `.cpp`

```plaintext
Collectible.h   What the class has
Collectible.cpp What the class does
```

The header lists components, properties, and functions. The `.cpp` file contains the working code.

## Unreal words

```cpp
UCLASS()
class UEINTRO_DEV_26_API ACollectible : public AActor
{
    GENERATED_BODY()
};
```

- `UCLASS()` makes the class visible to Unreal.
- `GENERATED_BODY()` adds code Unreal needs.
- `AActor` means the object can exist in a level.
- Leave `UEINTRO_DEV_26_API` unchanged.

```plaintext
AActor      An object in the world
APawn       An Actor that can be controlled
ACharacter  A Pawn with built-in movement
```

## Making a property appear

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
int32 Value = 1;
```

- `UPROPERTY` tells Unreal about the variable.
- `EditAnywhere` makes it editable in Details.
- `VisibleAnywhere` shows it but does not allow editing.
- `BlueprintReadOnly` lets Blueprint read it.
- `BlueprintReadWrite` lets Blueprint read and change it.
- `Category` chooses its group in Details.

```cpp
UFUNCTION(BlueprintCallable)
void AddCollectible();
```

`BlueprintCallable` makes a Blueprint node. `BlueprintPure` is for a function that only returns information.

## How `ACollectible` works

The constructor turns Tick off, creates a collision sphere, attaches a visible mesh, and listens for overlaps.

```cpp
AWorkshopCharacter* Player = Cast<AWorkshopCharacter>(OtherActor);
```

`Cast` checks whether the Actor is the player. If it is not, the function stops. If it is:

```cpp
Player->AddCollectible();
UE_LOG(LogTemp, Display, TEXT("Collected an item"));
Destroy();
```

The count goes up, a message appears in the Output Log, and `Destroy()` removes the collectible.

## Useful types

```plaintext
int32 whole number       float decimal number
bool true or false       FText text shown to players
FString text for code    FVector position or direction
FRotator rotation
```

## Main activity

Add this below `Value` in `Collectible.h`:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
bool bRare = false;
```

Save, build, return to Unreal, and open `BP_Collectible`. The new checkbox proves that C++ can create Editor properties.

## Finished early?

Try one at a time:

```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
int32 ScoreValue = 10;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collectible")
float Weight = 1.0f;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
FText Description;
```

Change a specifier and see what changes in the Details panel.
