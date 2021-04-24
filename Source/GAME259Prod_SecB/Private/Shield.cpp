// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"
#include "Kismet/GameplayStatics.h"
#include "../GAME259Prod_SecBCharacter.h"

UShield::UShield() {
	//_rootComponent = NewObject<UStaticMeshComponent>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//check(_rootComponent);
	//_rootComponent->RegisterComponent();

}

UShield::UShield(const FObjectInitializer& ObjectInitializer) {
//Create Shield here.

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	SetStaticMesh(mesh.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial> material(TEXT("Material'/Game/ProjectAmulet/Maps/Assets/Materials/Effects/Energy_Shield/M_Shield_001_ARA.M_Shield_001_ARA'"));
	
	//UMaterialInterface* mat = material.Object;
	SetMaterial(0, material.Object);
}

UShield::~UShield() {

}
//Does this work?
void UShield::BeginPlay_Implementation()
{
	Super::BeginPlay();
	//Set timer.
	FTimerHandle Timing;
	GetWorld()->GetTimerManager().SetTimer(Timing, this, &UShield::EndShield, 3.0f, false);
}

void UShield::Damage(float value) {
	shieldHealth -= value;

	if (shieldHealth <= 0) {
		EndShield();
	}
}

void UShield::EndShield()
{
	Cast<AGAME259Prod_SecBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))->isShielded = false;
	//Destroy Shield 
	DestroyComponent();
}
