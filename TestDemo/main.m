//
//  main.m
//  TestDemo
//
//  Created by WSN on 2021/11/4.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    [MPAnalysisHelper enableCrashReporterService]; // USE MPAAS CRASH REPORTER
    NSString *appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = @"DFClientDelegate";
    }
//    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
    return UIApplicationMain(argc, argv, @"DFApplication", appDelegateClassName);     // NOW USE MPAAS FRAMEWORK
}
