// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPCube.h"

#include "Components/BoxComponent.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

ACPPCube::ACPPCube()
{
 	// Выключаем тик, если он нам не нужен
 	PrimaryActorTick.bCanEverTick = false;

	// Устанавливаем компонент сцены как рутовый компонент
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("My Scene"));
	SetRootComponent(SceneComponent);
	//RootComponent = SceneComponent; // ещё вариант
	
	// Создаём статик меш компонент и настраиваем
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	// ConstructorHelpers помогает назначить ассет из С++ кода
	//static ConstructorHelpers::FObjectFinder<UStaticMesh>VisualAsset(TEXT("/Game/ThirdPerson/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer"));
	//StaticMesh->SetStaticMesh(VisualAsset.Object);
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetRelativeLocation(FVector(0,0,50));

	// Создаём компонент лампочку
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("My Point Light"));
	PointLight->SetupAttachment(StaticMesh);
	PointLight->SetLightColor(FLinearColor(1,0,0,1), true);
	PointLight->SetVisibility(false);
	PointLight->SetRelativeLocation(FVector(0,0,100));

	// Создаём компонент коллижн бокс
	// Больше про коллижн бокс https://youtu.be/TRTqRuBHajw?t=461
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Collision"));
	Box->SetupAttachment(StaticMesh);
	Box->SetBoxExtent(FVector(100,100,100), true);
	Box->SetRelativeLocation(FVector(0,0,50));

	// Подвязываем свою функцию на событие(диспатчер, делегат) оверлап внутри компонента
	Box->OnComponentBeginOverlap.AddDynamic(this, &ACPPCube::MyBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &ACPPCube::MyEndOverlap);
}

void ACPPCube::BeginPlay()
{
	Super::BeginPlay();
}

void ACPPCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// В нашем случае всё равно отключено в конструкторе класса
}

void ACPPCube::MyBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ACharacter>(OtherActor) == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		PointLight->SetVisibility(true);
	}
}

void ACPPCube::MyEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if(Cast<ACharacter>(OtherActor) == UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		PointLight->SetVisibility(false);
	}
}

void ACPPCube::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	// Почти PrintString
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Hello! I override NotifyActorBeginOverlap =)");
	// больше про логирование
	// https://www.chrismccole.com/blog/logging-in-ue4-cpp
	// https://www.unrealcommunity.wiki/logging-lgpidy6i
}

void ACPPCube::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Hello! I override NotifyActorEndOverlap =)");
}
