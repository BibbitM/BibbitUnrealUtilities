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
	/** Calculates the cosine of the angle between A and B. */
	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector")
	static double VectorCosine(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	/** Calculates the cosine of the angle between A and B. */
	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector2D")
	static double Vector2DCosine(const FVector2D& A, const FVector2D& B, double EpsilonSq = 1.e-8);

	/** Calculates the cosine of the angle between A and B using the XY plane (ignores Z). */
	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector")
	static double VectorCosine2D(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	/** Calculates the angle between A and B, in radians [0..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle (Radians)"), Category = "Math|Bibbit|Vector")
	static double VectorAngleInRadians(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	/** Calculates the angle between A and B, in degrees [0..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle (Degrees)"), Category = "Math|Bibbit|Vector")
	static double VectorAngleInDegrees(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	/** Calculates the angle between A and B, in radians [0..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Angle (Radians)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DAngleInRadians(const FVector2D& A, const FVector2D& B, double EpsilonSq = 1.e-8);

	/** Calculates the angle between A and B, in degrees [0..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Angle (Degrees)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DAngleInDegrees(const FVector2D& A, const FVector2D& B, double EpsilonSq = 1.e-8);

	/** Calculates the angle between A and B using the XY plane (ignores Z), in radians [0..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle 2D (Radians)"), Category = "Math|Bibbit|Vector")
	static double VectorAngle2DInRadians(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	/** Calculates the angle between A and B using the XY plane (ignores Z), in degrees [0..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle 2D (Degrees)"), Category = "Math|Bibbit|Vector")
	static double VectorAngle2DInDegrees(const FVector& A, const FVector& B, double EpsilonSq = 1.e-8);

	/** Calculates the signed angle from A to B around Axis, in radians [-PI..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle (Radians)", CPP_Default_Axis = "0,0,1"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngleInRadians(const FVector& A, const FVector& B, FVector Axis = FVector::UpVector);

	/** Calculates the signed angle from A to B around Axis, in degrees [-180..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle (Degrees)", CPP_Default_Axis = "0,0,1"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngleInDegrees(const FVector& A, const FVector& B, FVector Axis = FVector::UpVector);

	/** Calculates the signed angle from A to B in 2D, in radians [-PI..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Signed Angle (Radians)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DSignedAngleInRadians(const FVector2D& A, const FVector2D& B);

	/** Calculates the signed angle from A to B in 2D, in degrees [-180..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector2D Signed Angle (Degrees)"), Category = "Math|Bibbit|Vector2D")
	static double Vector2DSignedAngleInDegrees(const FVector2D& A, const FVector2D& B);

	/** Calculates the signed angle from A to B using the XY plane (ignores Z), in radians [-PI..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle 2D (Radians)"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngle2DInRadians(const FVector& A, const FVector& B);

	/** Calculates the signed angle from A to B using the XY plane (ignores Z), in degrees [-180..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle 2D (Degrees)"), Category = "Math|Bibbit|Vector")
	static double VectorSignedAngle2DInDegrees(const FVector& A, const FVector& B);

	/** Calculates a vector perpendicular to Vector on the plane defined by Axis. Returns zero if Axis is invalid or parallel. */
	UFUNCTION(BlueprintPure, meta = (CPP_Default_Axis = "0,0,1"), Category = "Math|Bibbit|Vector")
	static FVector VectorPerpendicular(const FVector& Vector, FVector Axis = FVector::UpVector);

	/** Calculates a vector perpendicular to Vector using the XY plane (ignores Z). */
	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector")
	static FVector VectorPerpendicular2D(const FVector& Vector);

	/** Calculates a vector perpendicular to Vector. */
	UFUNCTION(BlueprintPure, Category = "Math|Bibbit|Vector2D")
	static FVector2D Vector2DPerpendicular(const FVector2D& Vector);
};
