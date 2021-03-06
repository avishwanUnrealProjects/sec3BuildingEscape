// Copyright Notice Arun Vish

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float OpenDoorAngle = 0.f;

	UPROPERTY(EditAnywhere, BluePrintReadOnly)
	float DoorCloseDelay = 0.f;
	
	UPROPERTY(EditAnywhere, BluePrintReadOnly)
	float DoorOpenDelay = 0.f;
private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume * PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;

	float GetTotalMassOnPlate();
	// Actor that affects trigger volume
	//UPROPERTY(EditAnywhere)
	//AActor* ActorThatOpens;
	AActor* Owner = nullptr;	
	
};
