//
//  DNSServiceMetaQuery.h
//  TestServiceDiscovery
//
//  Created by Eoin Norris on 20/02/2018.
//  Copyright © 2018 Sweepr. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <dns_sd.h>

#ifndef _DNSSERVICE_H
#define _DNSSERVICE_H

typedef struct MyDNSServiceState {
    DNSServiceRef       service;
    CFRunLoopSourceRef  source;
    CFSocketRef         socket;
} MyDNSServiceState;


@interface DNSServiceQuery:NSObject
@property (atomic) MyDNSServiceState* query;
@end



@protocol DNSMetaQueryDelegate <NSObject>

-(void)serviceBecameAvailable:(NSString*) addedService;
-(void)serviceRemoved:(NSString*) removedService;

@end


@interface DNSMetaQuery:NSObject

@property(nonatomic, strong) id<DNSMetaQueryDelegate> delegate;
@property (nonatomic,strong) dispatch_queue_t queue;
@property (nonatomic) BOOL isDiscovering;


-(DNSServiceQuery*)startDiscoveryWithDelegate:(id<DNSMetaQueryDelegate>) delegate;
-(void)stopDiscoveryForService:(DNSServiceQuery*)service;

@end

#endif
