// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectible.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UPrimitiveComponent;

/**
 * A simple collectible Actor used by the beginner Unreal C++ workshop.
 */
UCLASS()
class UEINTRO_DEV_26_API ACollectible : public AActor
{
	GENERATED_BODY()

public:
	ACollectible();

	/** Sphere used to detect the player overlapping the collectible. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collectible")
	USphereComponent* Collision;

	/** Visible mesh attached to the collision sphere. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collectible")
	UStaticMeshComponent* Mesh;

	/** Name written to the Output Log when this item is collected. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
	FText DisplayName;

	/** Simple editable value for workshop exploration. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collectible")
	int32 Value = 1;

private:
	/** Handles actors entering the collision sphere. */
	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};
