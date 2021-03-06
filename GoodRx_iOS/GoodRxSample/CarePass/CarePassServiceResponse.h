/*
 * Copyright 2012 Aetna, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0.html
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#import <Foundation/Foundation.h>
#import "CarePassServiceRequest.h"
#import "CarePassClientException.h"
#import "CarePassServiceException.h"
#import "JSONKit.h"

@interface CarePassServiceResponse : NSObject {
    NSInteger            httpStatusCode;
    NSString             *requestId;
    NSMutableData        *body;
    NSException          *exception;
    bool                 isFinishedLoading;
    bool                 didTimeout;
    Class                unmarshallerDelegate;
    
    CarePassServiceRequest *request;
    
    NSTimeInterval       processingTime;
}

/** The body of the html response. */
@property (nonatomic, retain) NSData *body;

/** The HTTP status code of the response from the service. */
@property (nonatomic) NSInteger httpStatusCode;

/** Whether the response is finished loading. */
@property (nonatomic, readonly) bool isFinishedLoading;

/** Whether the original request was timed out. */
@property (nonatomic, readonly) bool didTimeout;

/** If an exception was thrown, this will return the exception. */
@property (nonatomic, readonly) NSException *exception;

/** The request for which this is the response */
@property (nonatomic, retain) CarePassServiceRequest *request;

/** The requestId assigned by the service */
@property (nonatomic, retain) NSString       *requestId;

@property (nonatomic, assign) Class          unmarshallerDelegate;
@property (nonatomic, assign) NSTimeInterval processingTime;


/** Once the body has been received, perform additional processing, such as parse JSON. */
-(void)processBody;
-(void)postProcess;


#pragma mark NSURLConnection delegate methods

/** delegate method for NSURLConnection */
-(void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response;
/** delegate method for NSURLConnection */
-(void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
/** delegate method for NSURLConnection */
-(void)connectionDidFinishLoading:(NSURLConnection *)connection;

@end
