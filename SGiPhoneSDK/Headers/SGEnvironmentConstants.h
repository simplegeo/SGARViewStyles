/*
 * SGEnvironmentConstants.h
 * CCLocatorServices
 *
 * Created by Derek Smith on 9/22/09.
 * Copyright 2010 SimpleGeo. All rights reserved.
 *
 */

/*!
 * @function SGSetEnvironmentViewingRadius
 * @abstract ￼ Sets the viewing radius of the AR view. The default is 100m.
 * @discussion The viewing radius determines what records are drawn in the AR view. If the distance
 * from the record to the current location is greater than the view radius, then the record will
 * not be drawn.
 * @param ￼ radius The radius in meters.
 */ 
extern void SGSetEnvironmentViewingRadius(float radius);

/*!
 * @function SGSetEnvironmentMaximumAnnotationDistance
 * @abstract ￼ Sets the maximum allowed distance for a record annotation view. The default is 100m.
 * @discussion ￼ This helps scale views to a decent size because the enviornment is orthogonal.
 * @param ￼ maxDistance The maximum distance for a record annotation view.
 */
extern void SGSetEnvironmentMaximumAnnotationDistance(float maxDistance);

/*!
 * @function SGSetEnvironmentMinimumAnnotationDistance
 * @abstract ￼ Sets the minimum allowed distance for a record annotation view. The default is 3m.
 * @discussion ￼ This helps keep record annotation views at a safe distance from device's current location.
 * @param ￼ minDistance The minimum distance for a record annotation view.
 */
extern void SGSetEnvironmentMinimumAnnotationDistance(float minDistance);
