//
//  SearchFacilitatorOrdersDelegateIMP.m
//  ServiceManager
//
//  Created by will.wang on 16/7/1.
//  Copyright © 2016年 wangzhi. All rights reserved.
//

#import "SearchFacilitatorOrdersDelegateIMP.h"

@implementation SearchFacilitatorOrdersDelegateIMP

- (void)queryOrderList:(PageInfo*)pageInfo response:(RequestCallBackBlockV2)requestCallBackBlock
{
    requestCallBackBlock(self.error, self.responseData, [MiscHelper filterOrders:self.allSearchedOrders byStatus:self.orderStatus]);
}

@end
