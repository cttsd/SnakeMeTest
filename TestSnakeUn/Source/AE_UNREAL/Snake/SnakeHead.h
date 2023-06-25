// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnakePart.h"
#include "SnakeHead.generated.h"

UCLASS()
class AE_UNREAL_API ASnakeHead : public ASnakePart
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnakeHead();
	void SaveDir(float _Value);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	
	
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �𸮾��� �������Ʈ�� �����Ҽ� �ְ� �� �Լ��� ��Ͻ������ �մϴ�.
	// �������Ʈ�� �� c++�Լ��� �˼��ְ� �������� �Ѵ�.
	// �Լ��� ��쿡�� 

	// �� UFUNCTION �𸮾��� �ν��ϰ� ���ذ� ���̰�
	// �������� �� �Լ��� ��� ���ϰ����� () �־���� �մϴ�.
	


	UFUNCTION(BlueprintCallable)
	void LeftMove(float _Value);

	UFUNCTION(BlueprintCallable)
	void RightMove(float _Value);

	UFUNCTION(BlueprintCallable)
	void UpMove(float _Value);

	UFUNCTION(BlueprintCallable)
	void DownMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void LeftAction(float _Value);

	UFUNCTION(BlueprintCallable)
		void RightAction(float _Value);

	UFUNCTION(BlueprintCallable)
		void UpAction(float _Value);

	UFUNCTION(BlueprintCallable)
		void DownAction(float _Value);
private:
	
	int Dir;
	
};
