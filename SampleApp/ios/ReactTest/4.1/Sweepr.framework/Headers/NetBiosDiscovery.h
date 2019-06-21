//
//  NetBiosDiscovery.h
//  testNetBios
//
//  Created by Eoin Norris on 27/07/2018.
//  Copyright © 2018 Sweepr. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NETBIOSEntry : NSObject
@property (nonatomic,strong) NSString* ipAddress;
@property (nonatomic,strong) NSString* name;
@property (nonatomic,strong) NSString* group;
@property (nonatomic,strong) NSString* type;
@property (nonatomic) int flag;
@property (nonatomic,strong) NSDate* lastTimeSeen;

@end


@protocol NETBIOSObserver <NSObject>
- (void)NETBIOSBRemoved:(NETBIOSEntry *)entry;
- (void)NETBIOSBUpdated:(NETBIOSEntry *)entry;
@end




@interface NetBiosDiscovery : NSObject<NETBIOSObserver>

@property (nonatomic, strong) id<NETBIOSObserver> delegate;


+ (instancetype)sharedInstance;
-(BOOL)stopDiscovering;
-(BOOL)startDiscoveringWithDelegate:(id<NETBIOSObserver>)observer;
@end
