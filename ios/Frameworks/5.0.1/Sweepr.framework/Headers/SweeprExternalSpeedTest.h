//
//  SweeprExternalSpeedTest.h
//  Sweepr
//
//  Created by Eoin Norris on 11/10/2018.
//  Copyright © 2018 Sweepr. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void (^ExternalSpeedResult)(double maxSpeed, BOOL finish);


@interface SweeprExternalSpeedTest : NSObject

@property (nonatomic, strong ) ExternalSpeedResult savedBlock;
@property (nonatomic,strong) dispatch_queue_t queue;



-(double)startSpeedTest:(int)duration progressBlock:(ExternalSpeedResult)blockName;
//-(double)startSpeedTest:(int)duration;

-(void)setDownloadSpeed:(double)downloadSpeed;
-(void)setFinished:(double)downloadSpeed;

    
@end
