// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "CPPCube.generated.h"

// Предупреждаем компилятор что эти классы будут описаны позже
// forward declarations
class USceneComponent;
class UStaticMeshComponent;
class UPointLightComponent;
class UBoxComponent;

UCLASS()
class TEST_API ACPPCube : public AActor
{
	GENERATED_BODY()
	
private:
	// Описываем состав компонентов нашего будущего актора
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Components)
	USceneComponent* SceneComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Components)
	UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Components)
	UPointLightComponent* PointLight = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = Components)
	UBoxComponent* Box = nullptr;
	
public:	
	// Устанавливает значения по умолчанию для свойств этого актера
	ACPPCube();

protected:
	// Вызывается при порождении в мире(спавне или старте игры)
	virtual void BeginPlay() override;
	// Вызывается каждый кадр
	virtual void Tick(float DeltaTime) override;

	// Переопределяю стандартные оверлапы актора
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
public:	
	// Собственные функции для подвязки на оверлапы компонента
	UFUNCTION()
		void MyBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void MyEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
