//
//  DNSResolver.h
//  Sweepr
//
//  Created by Eoin Norris on 25/07/2018.
//  Copyright © 2018 Sweepr. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DNSResolver : NSObject

+(NSArray<NSString*>*)hostnamesforAddress:(NSString*)address;

@end
