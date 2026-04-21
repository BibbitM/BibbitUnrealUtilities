// Copyright BIBBIT Michal Nowak.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "BibbitMathBlueprintLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class BIBBITUTILITIES_API UBibbitMathBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector")
	static double VectorCosine(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector2D")
	static double Vector2DCosine(const FVector2D& A, const FVector2D& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector")
	static double VectorCosine2D(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle (Radians)"), Category = "Math|Bibbit|Vector")
	static double VectorAngleInRadians(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle (Degrees)"), Category = "Math|Bibbit|Vector")
	static double VectorAngleInDegrees(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Angle (Radians)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DAngleInRadians(const FVector2D& A, const FVector2D& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Angle (Degrees)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DAngleInDegrees(const FVector2D& A, const FVector2D& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle 2D (Radians)"), Category = "Math|Bibbit|Vector")
	static double VectorAngle2DInRadians(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle 2D (Degrees)"), Category = "Math|Bibbit|Vector")
	static double VectorAngle2DInDegrees(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle (Radians)", CPP_Default_Axis = "0,0,1"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngleInRadians(const FVector& A, const FVector& B, FVector Axis = FVector::UpVector);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle (Degrees)", CPP_Default_Axis = "0,0,1"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngleInDegrees(const FVector& A, const FVector& B, FVector Axis = FVector::UpVector);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Signed Angle (Radians)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DSignedAngleInRadians(const FVector2D& A, const FVector2D& B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Signed Angle (Degrees)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DSignedAngleInDegrees(const FVector2D& A, const FVector2D& B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle 2D (Radians)"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngle2DInRadians(const FVector& A, const FVector& B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle 2D (Degrees)"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngle2DInDegrees(const FVector& A, const FVector& B);

	UFUNCTION(BlueprintPure, meta = (CPP_Default_Axis = "0,0,1"), Category = "Math|Bibbit|Vector")
	static FVector VectorPerpendicular(const FVector& Vector, FVector Axis = FVector::UpVector);

	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector")
	static FVector VectorPerpendicular2D(const FVector& Vector);

	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector2D")
	static FVector2D Vector2DPerpendicular(const FVector2D& Vector);
};
