/*
 Copyright (c) 2011, Tony Million.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE. 
 */

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

#import <sys/socket.h>
#import <netinet/in.h>
#import <netinet6/in6.h>
#import <arpa/inet.h>
#import <ifaddrs.h>
#import <netdb.h>

/**
 * Does ARC support support GCD objects?
 * It does if the minimum deployment target is iOS 6+ or Mac OS X 8+
 * 
 * @see http://opensource.apple.com/source/libdispatch/libdispatch-228.18/os/object.h
 **/
#if OS_OBJECT_USE_OBJC
#define NEEDS_DISPATCH_RETAIN_RELEASE 0
#else
#define NEEDS_DISPATCH_RETAIN_RELEASE 1
#endif


extern NSString *const kMPAASReachabilityChangedNotification;

typedef enum 
{
	// Apple NetworkStatus Compatible Names.
	MPAASNotReachable     = 0,
    MPAASReachableViaWWAN = 1,
	MPAASReachableViaWiFi = 2,
} MPAASNetworkStatus;

typedef enum
{
    MPAASNNotReachable     = 0,
    MPAASNReachableViaWWAN2G = 1,
    MPAASNReachableViaWWAN3G = 2,
    MPAASNReachableViaWWAN4G = 3,
    MPAASNReachableViaWiFi = 4,
    MPAASNReachableViaUnknown = 5,
} MPAASNNetworkStatus;

@class DTNetReachability;

typedef void (^MPAASNetworkReachable)(DTNetReachability * reachability);
typedef void (^MPAASNetworkUnreachable)(DTNetReachability * reachability);

@interface DTNetReachability : NSObject

@property (nonatomic, copy) MPAASNetworkReachable    reachableBlock;
@property (nonatomic, copy) MPAASNetworkUnreachable  unreachableBlock;


@property (nonatomic, assign) BOOL reachableOnWWAN;
/**
 *  ??????hostname??????DTNetReachability
 *
 *  @param hostname ?????????
 *
 *  @return DTNetReachability
 */
+(DTNetReachability*)reachabilityWithHostname:(NSString*)hostname;
/**
 *  ??????DTNetReachability
 *
 *  @return DTNetReachability
 */
+(DTNetReachability*)reachabilityForInternetConnection;
/**
 *  ??????hostaddress??????DTNetReachability
 *
 *  @param hostAddress ????????????
 *
 *  @return DTNetReachability
 */
+(DTNetReachability*)reachabilityWithAddress:(const struct sockaddr_in*)hostAddress;
/**
 *  ????????????wifi??????DTNetReachability
 *
 *  @return DTNetReachability
 */
+(DTNetReachability*)reachabilityForLocalWiFi;
/**
 *  ?????????DTNetReachability
 *
 *  @param ref SCNetworkReachabilityRef
 *
 *  @return DTNetReachability
 */
-(DTNetReachability *)initWithReachabilityRef:(SCNetworkReachabilityRef)ref;
/**
 *  ????????????
 *
 *  @return yes/no
 */
-(BOOL)startNotifier;
/**
 *  ????????????
 *
 *  @return yes/no
 */
-(void)stopNotifier;
/**
 *  ???????????????
 *
 *  @return yes/no
 */
-(BOOL)isReachable;
/**
 *  ?????????????????????
 *
 *  @return yes/no
 */
-(BOOL)isReachableViaWWAN;
/**
 *  wifi???????????????
 *
 *  @return yes/no
 */
-(BOOL)isReachableViaWiFi;
/**
 *  4G???????????????
 *
 *  @return yes/no
 */
- (BOOL)isReachableVia4G;
/**
 *  3G???????????????
 *
 *  @return yes/no
 */
-(BOOL)isReachableVia3G;
/**
 *  2G???????????????
 *
 *  @return yes/no
 */
-(BOOL)isReachableVia2G;
/**
 *  WWAN may be available, but not active until a connection has been established.
 *  WiFi may require a connection for VPN on Demand.
 */
-(BOOL)isConnectionRequired; // Identical DDG variant.
/**
 *  Apple's routine.
 */
-(BOOL)connectionRequired; //
/**
 *  Dynamic, on demand connection?
 */
-(BOOL)isConnectionOnDemand;
/**
 *  Is user intervention required?
 */
-(BOOL)isInterventionRequired;
/**
 *  ??????????????????????????????
 *
 *  @return ?????? noreach wifi wwan
 */
-(MPAASNetworkStatus)currentReachabilityStatus;
/**
 *  ??????????????????????????????
 *
 *  @return ?????? noreach wifi 2G 3G 4G
 */
-(MPAASNNetworkStatus)getCurrentReachabilityStatus;
/**
 *  ??????????????????????????????
 *
 *  @return ??????
 */
-(SCNetworkReachabilityFlags)reachabilityFlags;
/**
 *  ?????????????????????????????????
 *
 *  @return ??????
 */
-(NSString*)currentReachabilityString;
/**
 *  ?????????????????????????????????
 *
 *  @return ??????
 */
-(NSString*)currentReachabilityFlags;

@end
