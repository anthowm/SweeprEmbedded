//
//  SweeprUmbrella.h
//  Sweepr
//
//  Created by Eoin Norris on 13/02/2018.
//  Copyright © 2018 Sweepr. All rights reserved.
//

#ifndef SweeprUmbrella_h
#define SweeprUmbrella_h

#import "MacFinder.h"
#import "SimplePing.h"
#import "DNSServiceMetaQuery.h"
#import "upnpx.h"
#import "GateWay.h"
#import "DNSResolver.h"
#import "Sweepr.h"
#import "NetBiosDiscovery.h"
#import "SweeprExternalSpeedTest.h"

typedef NS_OPTIONS(NSInteger, SweeprScanOptions) {
    Demo        = 1,
    Ping        = 1 << 0,
    MacAddress  = 1 << 1,
    Bonjour     = 1 << 2,
    UpNP = 1 << 3,
    All = 16
};

typedef NS_OPTIONS(NSInteger, SweeprDeviceOptions) {
    pingDeviceSubnet        = 1,
    pingAll        = 1 << 0
};

#endif /* SweeprUmbrella_h */
