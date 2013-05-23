//
//  PSPDFLineHelper.h
//  PSPDFKit
//
//  Copyright (c) 2013 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY AUSTRIAN COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PSPDFLineEndType) {
    PSPDFLineEndTypeNone,
    PSPDFLineEndTypeSquare,
    PSPDFLineEndTypeCircle,
    PSPDFLineEndTypeDiamond,
    PSPDFLineEndTypeOpenArrow,
    PSPDFLineEndTypeClosedArrow,
    PSPDFLineEndTypeButt,
    PSPDFLineEndTypeReverseOpenArrow,
    PSPDFLineEndTypeReverseClosedArrow,
    PSPDFLineEndTypeSlash
};

/// Draws a polyline between all given points. The two ends of this line can have a PSPDFLineEndType.
extern void PSPDFDrawPolyLine(CGContextRef context, CGPoint *points, NSUInteger pointsCount, PSPDFLineEndType lineEnd1, PSPDFLineEndType lineEnd2, CGFloat lineWidth);

/// Draws a line between two points with the specified line end types.
extern void PSPDFDrawLine(CGContextRef context, CGPoint point1, CGPoint point2, PSPDFLineEndType lineEnd1, PSPDFLineEndType lineEnd2, CGFloat lineWidth);

/// Returns whether the line end type requires a full line.
/// A full line is required if the line end type directly "connects" to the line, e.g. for an open arrow.
extern BOOL PSPDFLineEndNeedsFullLine(PSPDFLineEndType lineEnd);

/// Transforms line end type <-> line end string (PDF reference).
extern NSValueTransformer *PSPDFGetLineEndTypeTransformer(void);
