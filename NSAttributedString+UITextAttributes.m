//
//  NSAttributedString+UITextAttributes.m
//  QuickTemplate
//
//  Created by Jason Jobe on 9/29/13.
//  Copyright (c) 2013 Jason Jobe. All rights reserved.
//

#import "NSAttributedString+UITextAttributes.h"
#import <UIKit/UIKit.h>


@implementation NSAttributedString (UITextAttributes)

- (NSAttributedString*)attributedStringWithCurrentTextStyle
{
    
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithAttributedString:self  ];
    NSRange range = NSMakeRange(0, attributedString.length - 1);
    
    // Walk the string's attributes
    [attributedString enumerateAttributesInRange:range options:NSAttributedStringEnumerationReverse usingBlock:
     ^(NSDictionary *attributes, NSRange range, BOOL *stop) {
         
         // Find the font descriptor which is based on the old font size change
         NSMutableDictionary *mutableAttributes = [NSMutableDictionary dictionaryWithDictionary:attributes];
         UIFont *font = mutableAttributes[@"NSFont"];
         UIFontDescriptor *fontDescriptor = font.fontDescriptor;
         
         // Get the text style and get a new font descriptor based on the style and update font size
         id styleAttribute = [fontDescriptor objectForKey:UIFontDescriptorTextStyleAttribute];
         UIFontDescriptor *newFontDescriptor = [UIFontDescriptor preferredFontDescriptorWithTextStyle:styleAttribute];
         
         // Get the new font from the new font descriptor and update the font attribute over the range
         UIFont *newFont = [UIFont fontWithDescriptor:newFontDescriptor size:0.0];
         [attributedString addAttribute:NSFontAttributeName value:newFont range:range];
     }];
    
    return attributedString;
}


@end
