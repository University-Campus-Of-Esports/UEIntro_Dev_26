// Copyright Epic Games, Inc. All Rights Reserved.

#include "Collectible.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WorkshopCharacter.h"

ACollectible::ACollectible()
{
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	SetRootComponent(Collision);
	Collision->InitSphereRadius(50.0f);
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collision->SetCollisionResponseToAllChannels(ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ACollectible::OnOverlapBegin);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	DisplayName = NSLOCTEXT("Collectible", "DefaultDisplayName", "Collectible");
}

void ACollectible::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	AWorkshopCharacter* WorkshopCharacter = Cast<AWorkshopCharacter>(OtherActor);

	if (WorkshopCharacter == nullptr)
	{
		return;
	}

	WorkshopCharacter->AddCollectible();
	UE_LOG(LogTemp, Display, TEXT("Collected: %s"), *DisplayName.ToString());
	Destroy();
}
