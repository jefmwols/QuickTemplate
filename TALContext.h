//
//  TALContext.h
//  WTTAL
//
//  Created by Jason Jobe on 1/23/07.
//  Copyright (c) 2007, 2013 Jason Jobe. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TALContext : NSObject
{
}

@property (strong, nonatomic) NSString *TAL_prefix;
@property (strong, nonatomic) NSString *TAL_condition;
@property (strong, nonatomic) NSString *TAL_content;
@property (strong, nonatomic) NSString *TAL_replace;
@property (strong, nonatomic) NSString *TAL_attributes;
@property (strong, nonatomic) NSString *TAL_omit;
@property (strong, nonatomic) NSString *TAL_include;
@property (strong, nonatomic) NSString *TAL_repeat;


@property (weak, nonatomic) id delegate;
@property (strong, nonatomic) NSMutableDictionary *defines;
@property (strong, nonatomic) NSMutableDictionary *loops;
@property (strong, nonatomic) NSMutableDictionary *values;

@property (assign, nonatomic) BOOL debug;

- initWithValues:(NSDictionary*)vals;
- initWithValues:(NSDictionary*)vals prefix:(NSString*)prefix;

- (void)initiateLoop:(NSString*)name withArray:(NSArray*)anArray;
- nextObjectForLoop:(NSString*)name;

- (NSString*)resourcePathForKey:(NSString*)key;
- (NSXMLDocument*)loadContentsOfResource:(NSString*)key;

-(void)setDelegate:anObject;
- delegate;

-(BOOL)debug;


// Template processing
-(NSXMLDocument*)documentUsingTemplate:(NSXMLDocument*)templateDoc;
-(NSXMLDocument*)documentUsingTemplateURL:(NSURL*)templateURL;
-(NSXMLDocument*)documentUsingTemplateURL:(NSURL*)url withValue:value forKey:(NSString*)key;

@end
