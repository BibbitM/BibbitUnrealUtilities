// Copyright BIBBIT Michal Nowak.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "BibbitMathBlueprintLibrary.generated.h"

UCLASS(meta = (BlueprintThreadSafe))
class BIBBITUTILITIES_API UBibbitMathBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Calculates the cosine of the angle between A and B.
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector")
	static double VectorCosine(FVector A, FVector B, double EpsilonSq = 1.e-6);

	/** Calculates the cosine of the angle between A and B.
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector 2D Cosine", AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector2D")
	static double Vector2DCosine(FVector2D A, FVector2D B, double EpsilonSq = 1.e-6);

	/** Calculates the cosine of the angle between A and B using the XY plane (ignores Z).
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector")
	static double VectorCosine2D(FVector A, FVector B, double EpsilonSq = 1.e-6);

	/** Calculates the angle between A and B, in radians [0..PI].
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle (Radians)", AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector")
	static double VectorAngleInRadians(FVector A, FVector B, double EpsilonSq = 1.e-6);

	/** Calculates the angle between A and B, in degrees [0..180].
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle (Degrees)", AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector")
	static double VectorAngleInDegrees(FVector A, FVector B, double EpsilonSq = 1.e-6);

	/** Calculates the angle between A and B, in radians [0..PI].
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector 2D Angle (Radians)", AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector2D")
	static double Vector2DAngleInRadians(FVector2D A, FVector2D B, double EpsilonSq = 1.e-6);

	/** Calculates the angle between A and B, in degrees [0..180].
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector 2D Angle (Degrees)", AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector2D")
	static double Vector2DAngleInDegrees(FVector2D A, FVector2D B, double EpsilonSq = 1.e-6);

	/** Calculates the angle between A and B using the XY plane (ignores Z), in radians [0..PI].
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle 2D (Radians)", AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector")
	static double VectorAngle2DInRadians(FVector A, FVector B, double EpsilonSq = 1.e-6);

	/** Calculates the angle between A and B using the XY plane (ignores Z), in degrees [0..180].
	 * @param EpsilonSq Squared epsilon for vector normalization. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Angle 2D (Degrees)", AdvancedDisplay = "EpsilonSq"), Category = "Bibbit|Math|Vector")
	static double VectorAngle2DInDegrees(FVector A, FVector B, double EpsilonSq = 1.e-6);

	/** Calculates the signed angle from A to B around Axis, in radians [-PI..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle (Radians)", CPP_Default_Axis = "0,0,1"), Category = "Bibbit|Math|Vector")
	static double VectorSignedAngleInRadians(FVector A, FVector B, FVector Axis = FVector::UpVector);

	/** Calculates the signed angle from A to B around Axis, in degrees [-180..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle (Degrees)", CPP_Default_Axis = "0,0,1"), Category = "Bibbit|Math|Vector")
	static double VectorSignedAngleInDegrees(FVector A, FVector B, FVector Axis = FVector::UpVector);

	/** Calculates the signed angle from A to B in 2D, in radians [-PI..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector 2D Signed Angle (Radians)"), Category = "Bibbit|Math|Vector2D")
	static double Vector2DSignedAngleInRadians(FVector2D A, FVector2D B);

	/** Calculates the signed angle from A to B in 2D, in degrees [-180..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector 2D Signed Angle (Degrees)"), Category = "Bibbit|Math|Vector2D")
	static double Vector2DSignedAngleInDegrees(FVector2D A, FVector2D B);

	/** Calculates the signed angle from A to B using the XY plane (ignores Z), in radians [-PI..PI]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle 2D (Radians)"), Category = "Bibbit|Math|Vector")
	static double VectorSignedAngle2DInRadians(FVector A, FVector B);

	/** Calculates the signed angle from A to B using the XY plane (ignores Z), in degrees [-180..180]. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector Signed Angle 2D (Degrees)"), Category = "Bibbit|Math|Vector")
	static double VectorSignedAngle2DInDegrees(FVector A, FVector B);

	/** Calculates a vector perpendicular to Vector on the plane defined by Axis. Returns zero if Axis is invalid or parallel. */
	UFUNCTION(BlueprintPure, meta = (CPP_Default_Axis = "0,0,1"), Category = "Bibbit|Math|Vector")
	static FVector VectorPerpendicular(FVector Vector, FVector Axis = FVector::UpVector);

	/** Calculates a vector perpendicular to Vector using the XY plane (ignores Z). */
	UFUNCTION(BlueprintPure, Category = "Bibbit|Math|Vector")
	static FVector VectorPerpendicular2D(FVector Vector);

	/** Calculates a vector perpendicular to Vector. */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Vector 2D Perpendicular"), Category = "Bibbit|Math|Vector2D")
	static FVector2D Vector2DPerpendicular(FVector2D Vector);
};
