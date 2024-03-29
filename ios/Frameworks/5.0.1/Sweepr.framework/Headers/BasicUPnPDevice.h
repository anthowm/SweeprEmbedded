// **********************************************************************************
//
// BSD License.
// This file is part of upnpx.
//
// Copyright (c) 2010-2011, Bruno Keymolen, email: bruno.keymolen@gmail.com
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, 
// this list of conditions and the following disclaimer.
// Redistributions in binary form must reproduce the above copyright notice, this 
// list of conditions and the following disclaimer in the documentation and/or other 
// materials provided with the distribution.
// Neither the name of "Bruno Keymolen" nor the names of its contributors may be 
// used to endorse or promote products derived from this software without specific 
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;LOSS OF USE, DATA, OR 
// PROFITS;OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
//
// **********************************************************************************


#import <Foundation/Foundation.h>
#import "SSDPDB_ObjC.h"
//#import "BasicUPnPService.h"
@class BasicUPnPService;



@class BasicUPnPDevice;


@protocol BasicUPnPDeviceObserver <NSObject>

- (void)deviceServicesDidUpdate:(BasicUPnPDevice *)device;

@end


@interface BasicUPnPDevice : NSObject {
@private
    bool isRoot;
    bool isFound;
    bool isLoadingDescriptionXML;
    double lastUpdated;
    NSMutableDictionary *services; //Key=urn string, Object=BasicUPnPService 
    NSString *uuid;
    NSString *type;

    NSString *xmlLocation;
    NSURL *baseURL;
    NSString *baseURLString;
    NSString *friendlyName;
    NSString *manufacturer;
    NSString *modelDescription;
    NSString *modelName;
    NSString *modelNumber;
    NSString *serialNumber;
    NSString *udn;
    NSString *usn;
    NSString *urn;
    int smallIconHeight;
    int smallIconWidth;
    int smallIconDepth;
    NSString *smallIconURL;
}

@property (readonly) bool isRoot;
@property (readwrite) bool isFound;
@property (readwrite) bool isLoadingDescriptionXML;
@property (readwrite) double lastUpdated;
@property (readonly) NSString *uuid;
@property (readonly) NSString *type;
@property (readonly) NSString *xmlLocation;
@property (readwrite, strong) NSURL *baseURL;
@property (readwrite, strong) NSString *baseURLString;
@property (readwrite, strong) NSString *friendlyName;
@property (nonatomic, strong) NSString *manufacturer;
@property (nonatomic, strong) NSURL *manufacturerURL;
@property (nonatomic, strong) NSString *manufacturerURLString;
@property (nonatomic, strong) NSString *modelDescription;
@property (nonatomic, strong) NSString *modelName;
@property (nonatomic, strong) NSString *modelNumber;
@property (nonatomic, strong) NSURL *modelURL;
@property (nonatomic, strong) NSString *modelURLString;
@property (nonatomic, strong) NSString *serialNumber;
@property (readwrite, strong) NSString *udn;
@property (readwrite, strong) NSString *usn;
@property (readwrite, strong) NSString *urn;
@property (readwrite, strong) NSString *smallIconURL;

@property (NS_NONATOMIC_IOSONLY, copy, getter=getServices, readonly) NSMutableDictionary<NSString *, BasicUPnPService *> *services;

- (instancetype)initWithSSDPDevice:(SSDPDBDevice_ObjC*)ssdp;
- (BasicUPnPService *)getServiceForType:(NSString*)serviceUrn;

- (int)loadDeviceDescriptionFromXML;
- (NSString*)localIPAddress;

- (NSUInteger)addObserver:(id <BasicUPnPDeviceObserver>)obs;
- (NSUInteger)removeObserver:(id <BasicUPnPDeviceObserver>)obs;

@end
