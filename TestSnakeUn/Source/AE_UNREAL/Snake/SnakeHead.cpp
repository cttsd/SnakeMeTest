// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeHead.h"
#include "SnakeGameMode.h"

// Sets default values
ASnakeHead::ASnakeHead()
{
	Dir = 0;
	
	// �𸮾󿡼� �����Ӹ��� Tick�� ������ �ϴ� ���ʹ�
	// PrimaryActorTick.bCanEverTick = true; �� �������� Tick�� �������� �ֽ��ϴ�.
	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// �����ڿ��� ���� �������ִ°� �Ϲ����ε�. 
	// ƽ�� �����ų� ���ų�
	PrimaryActorTick.bCanEverTick = true;
	// PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;
	

}


// Called when the game starts or when spawned
void ASnakeHead::BeginPlay()
{
	Super::BeginPlay();

}
void ASnakeHead::SaveDir(float _Value)
{
	Dir = _Value; // ���� �ൿ ����
}



// Called every frame
void ASnakeHead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ASnakeHead::LeftMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector);
}


void ASnakeHead::RightMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector);
}
void ASnakeHead::UpMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::UpVector);
}
void ASnakeHead::DownMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::DownVector);
}

void ASnakeHead::LeftAction(float _Value)
{
	FVector MovePos = FVector::LeftVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}
	

	if (Dir != 2)
	{
		Dir = 1;
		AddActorLocalOffset(FVector::LeftVector * 100.0f);

	}

	

	

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}

}
void ASnakeHead::RightAction(float _Value)
{
	FVector MovePos = FVector::RightVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}
	

	if (Dir != 1)
	{
		Dir = 2;
		AddActorLocalOffset(FVector::RightVector * 100.0f);;

	}

	

	
	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}

}
void ASnakeHead::UpAction(float _Value)
{
	FVector MovePos = FVector::UpVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}
	

	if (Dir != 3)
	{
		Dir = 0;
		AddActorLocalOffset(FVector::UpVector * 100.0f);

	}

	

	

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}
}
void ASnakeHead::DownAction(float _Value)
{
	FVector MovePos = FVector::DownVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}
	
	
	if (Dir != 0)
	{
		Dir = 3;
		AddActorLocalOffset(FVector::DownVector * 100.0f);

	}

	// �̵��� �ϰ� ����
	

	

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
	}
}