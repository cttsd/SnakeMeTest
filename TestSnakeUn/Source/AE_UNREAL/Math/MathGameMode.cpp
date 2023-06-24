// Fill out your copyright notice in the Description page of Project Settings.


#include "MathGameMode.h"
#include "Kismet/GameplayStatics.h"

void AMathGameMode::BeginPlay()
{
	{
		TArray<AActor*> AllActor;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Main", AllActor);

		if (1 != AllActor.Num())
		{
			UE_LOG(LogTemp, Error, TEXT("%S(%u)> Main Actor Is nullptr"), __FUNCTION__, __LINE__);
			return;
		}

		MainActor = AllActor[0];
	}

	{
		// �ѹ��� �Ϻ��ϰ� ġ�������� �ʴ´�. 
		// ���¿� ����� �ڵ带 ġ��
		// ����ó���� ��û �Ű�Ἥ ���ش�.
		// ���ܿ� �ɸ��� ���� ���߸� �ߴ��� �˾Ƴ��Եǰ�
		// ������ �����鼭 �Ϻ��� �ڵ尡 �ǰ� �ȴ�.
		
		// �ѹ��� �Ϻ��� �ڵ带 ġ���� ������� ������
		// �׳� �ƹ��͵� ���ϴ°�ó�� ���δ�.
		// �� ��Ÿ���� ������� ���� ����� ���մϴ�.
		// 10�и��� �����Ϸ� 20�и��� �Ϻ��� �ڵ� ��ħ.
		// ����� ����. => �ڵ带 �׳� ��ġ�� �ִ�.
		
		// ������ �ɰ��� �ϳ��ϳ��� ������
		// �̰� ���۾��ϴ� ��Ȳ�� ���ܸ� �� �ɾ���´�.
		// �ѹ��ڱ��� �������� ����� �ְ�
		// �ڽ��� ���� �ڵ带 �����ߴ��� ��

		TArray<AActor*> AllActor;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Other", AllActor);

		if (1 != AllActor.Num())
		{
			UE_LOG(LogTemp, Error, TEXT("%S(%u)> Main Actor Is nullptr"), __FUNCTION__, __LINE__);
			return;
		}

		OtherActor = AllActor[0];
	}

}

void AMathGameMode::Tick(float _Delta) 
{
	if (nullptr == MainActor || nullptr == OtherActor)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == MainActor || nullptr == OtherActor)"), __FUNCTION__, __LINE__);
		return;
	}

	switch (OtherActorState)
	{
	case OtherState::Idle:
		break;
	case OtherState::Trace:
		OtherActor->AddActorLocalOffset(FVector::LeftVector);
		break;
	default:
		break;
	}
	

	// ���Ͱ��� �θ��ڽİ��踦 �ξ��ټ� �ֽ��ϴ�.
	// MainActor->AddActorLocalOffset(FVector::LeftVector);

	//AActor* Main = nullptr;
	//AActor* Other = nullptr;

	//Other->GetActorLocation();

}