//
//  Bridging.m
//  AgentMate
//
//  Created by Softcake on 6/12/2558 BE.
//
//

#import "Bridging.h"
#import "PDFlib_ios/PDFlib_objc.h"
#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#define ApplicationDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)
@implementation Bridging

#pragma mark - Event: callEvent
- (void)callEvent:(CDVInvokedUrlCommand *)command {
    NSString *event = command.arguments[0];
    NSLog(@"Event %@ ", event);
    if ([event isEqualToString:@"writePDF"]) {
        NSLog(@"Yes");
    }else{
        NSLog(@"No");
    }
    NSDictionary *payload = [self convertPayload:command.arguments[1] callbackId:command.callbackId];
    [self performSelector:NSSelectorFromString([NSString stringWithFormat:@"%@:", event]) withObject:payload afterDelay:0];
}



- (NSDictionary *)convertPayload:(id)payload callbackId:(NSString *)callbackId {
    if ([payload isKindOfClass:[NSNull class]]) {
        return @{@"callbackId": callbackId};
    }
    
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionaryWithDictionary:payload];
    [dictionary setObject:callbackId forKey:@"callbackId"];
    return [dictionary copy];
}

- (NSData *)writePDF:(NSDictionary *)data{
    NSLog(@"In function writePDF! : %@", data);
    NSLog(@"data is %@", data[@"data"]);
    //NSDictionary *jsonDict = [NSJSONSerialization JSONObjectWithData:data[@"data"] options:0 error:nil];
    NSDictionary *dict = data[@"data"];
    NSLog(@"dict is %@", dict);
    NSLog(@"fontsize is %@", data[@"font_size"]);
    const double width = 595, height = 842;
    NSInteger           manual, page;
    NSInteger           font, row, col, gentiumfont;
    const NSInteger     maxrow = 1;
    const NSInteger     maxcol = 1;
    NSString           *optlist;
    NSInteger           endpage=0;
    NSInteger           pageno;
    NSString *pdfName = @"ArtworkBlankApp";
    NSString *infile = [[NSBundle mainBundle]
                        pathForResource:pdfName ofType:@"pdf"];
    //NSLog(@"%@", infile);
    /* This is where font/image/PDF input files live. Adjust as necessary. */
    NSString *searchpath = [[NSBundle mainBundle] resourcePath];
    NSLog(@"SearchPath: %@",searchpath);
    
    //Mark - webview test
    
//    UIWebView *webView = [[UIWebView alloc]init];
//    NSString *urlString = @"http://www.sourcefreeze.com";
//    NSURL *url = [NSURL URLWithString:urlString];
//    NSURLRequest *urlRequest = [NSURLRequest requestWithURL:url];
//    [webView loadRequest:urlRequest];
//    [ApplicationDelegate.window.rootViewController.view addSubview:webView];
//    

    PDFlib *pdflib = [[PDFlib alloc] init];
    if (!pdflib) {
        return nil;
    }
    @try
    {
        [pdflib set_option:@"errorpolicy=exception"];
        
        // Set the search path for fonts and PDF files
        [pdflib set_option:[NSString stringWithFormat:@"SearchPath={{%@}}", searchpath]];
        [pdflib set_option:@"license=i900203-010059-138172-KWKNG2-9SJTG2"];
        [pdflib begin_document:@"out.pdf" optlist:@""];
        
        [pdflib set_info:@"Creator" value:@"quickreference_ios"];
        [pdflib set_info:@"Author" value:@"Thomas Merz"];
        [pdflib set_info:@"Title" value:@"mini imposition demo (Objective-C)"];
        
        manual = [pdflib open_pdi_document:infile optlist:@""];
        endpage = [pdflib pcos_get_number:manual path:@"length:pages"];
        //NSLog(@"ENdpage is %ld",(long)endpage);
        
        [pdflib set_option:@"FontOutline={THSarabun=THSarabun.ttf}"];
        font = [pdflib load_font:@"THSarabun" encoding:@"unicode" optlist:@""];
        //NSLog(@"font %ld", (long)font);
        for (pageno = 1; pageno <= endpage; pageno++)
        {
            NSArray *pageArray = dict[[NSString stringWithFormat:@"%ld",pageno]];
            //NSLog(@"array: %@", pageArray);
            [pdflib begin_page_ext:width height:height optlist:@"topdown"];
            page = [pdflib open_pdi_page:manual pagenumber:pageno optlist:@""];
            optlist =  [NSString stringWithFormat:@"scale %f", 1.0 ];
            [pdflib fit_pdi_page:page x:0 y:height optlist:optlist];
            [pdflib close_pdi_page:page];
            [pdflib setfont:font fontsize:11];
            if(pageArray != NULL)
            {
                for (NSDictionary *pageDict in pageArray)
                {
                    [pdflib fit_textline:pageDict[@"text"] x:[pageDict[@"x"] integerValue] y:[pageDict[@"y"] integerValue] optlist:pageDict[@"optlist"]];
                }
            }
            [pdflib end_page_ext:@""];
        }
        [pdflib end_document:@""];
        [pdflib close_pdi_document:manual];
        
        NSData *pdfdata = [pdflib get_buffer];
        NSLog(@"pdf ........> %@", pdfdata);
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArrayBuffer:pdfdata] callbackId:data[@"callbackId"]];
        NSLog(@"Done!");
    }
    @catch (PDFlibException *ex)
    {
        NSString * errorMessage =
        [NSString stringWithFormat:@"PDFlib error %ld in '%@': %@",
         (long)[ex get_errnum], [ex get_apiname], [ex get_errmsg]];
        [self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:errorMessage ] callbackId:data[@"callbackId"]];
    }
    //[self.commandDelegate sendPluginResult:[CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"success"] callbackId:data[@"callbackId"]];
}


@end
