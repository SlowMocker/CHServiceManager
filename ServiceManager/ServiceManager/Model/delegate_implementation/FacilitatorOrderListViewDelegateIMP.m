//
//  ImpCommonOrderListDelegate.m
//  ServiceManager
//
//  Created by mac on 15/8/27.
//  Copyright (c) 2015年 wangzhi. All rights reserved.
//

#import "FacilitatorOrderListViewDelegateIMP.h"
#import "OrderTableViewCellDataSetter.h"

@implementation FacilitatorOrderListViewDelegateIMP

#pragma mark - override supper methods

- (void)queryOrderList:(PageInfo*)pageInfo response:(RequestCallBackBlockV2)requestCallBackBlock
{
    FacilitatorOrderListInPutParams *input = [FacilitatorOrderListInPutParams new];
    input.pagenow = [NSString intStr:pageInfo.currentPage];
    input.partner = self.user.userId;
    input.status = [NSString intStr:self.orderStatus];
    input.brands = [Util defaultStr:@"" ifStrEmpty:self.filterCondition.brands];
    input.productTypes = [Util defaultStr:@"" ifStrEmpty:self.filterCondition.productTypes];
    input.orderTypes = [Util defaultStr:@"" ifStrEmpty:self.filterCondition.orderTypes];

    [self.httpClient facilitator_orderList:input response:^(NSError *error, HttpResponseData *responseData) {
        NSArray *orderItems;
        if (!error && kHttpReturnCodeSuccess == responseData.resultCode) {
            orderItems = [MiscHelper parserOrderList:responseData.resultData];
        }
        requestCallBackBlock(error, responseData, orderItems);
    }];
}

- (void)agreeOrder:(OrderContent*)order response:(RequestCallBackBlock)requestCallBackBlock
{
    OrderContentModel *orderModel = (OrderContentModel*)order;
    RefuseOrderInputParams *input = [RefuseOrderInputParams new];
    input.object_id = [orderModel.object_id description];
    input.flag = @"0";

    [Util showWaitingDialog];
    [self.httpClient facilitator_refuseOrder:input response:^(NSError *error, HttpResponseData *responseData) {
        [Util dismissWaitingDialog];
        requestCallBackBlock(error, responseData);
    }];
}

- (NSString*)getExNoteStrWhenAgreeingOrder:(OrderContent*)order
{
    OrderContentModel *orderModel = (OrderContentModel*)order;
    BOOL bUnappointmented = [orderModel.status isEqualOneInArray:@[@"SR01",@"SR20",@"SR40"]];
    NSString *exNoteStr = @"";

    if ([orderModel.source isEqualToString:@"73"] && bUnappointmented) { //tmall order
        exNoteStr = @"\"天猫\"工单，请在1小时内预约，严格按照预约时间上门，并按公司标准收费";
    }
    return exNoteStr;
}

- (void)refuseOrder:(OrderContent*)order reason:(CheckItemModel*)reason response:(RequestCallBackBlock)requestCallBackBlock
{
    OrderContentModel *orderModel = (OrderContentModel*)order;
    RefuseOrderInputParams *refuseItem = [RefuseOrderInputParams new];
    refuseItem.object_id = orderModel.object_id;
    refuseItem.flag = @"1";
    refuseItem.reason = reason.key;
    refuseItem.memo = (NSString*)reason.extData;

    [Util showWaitingDialog];
    [self.httpClient facilitator_refuseOrder:refuseItem response:^(NSError *error, HttpResponseData *responseData) {
        [Util dismissWaitingDialog];
        requestCallBackBlock(error, responseData);
    }];
}

- (void)setCell:(OrderTableViewCell *)cell withData:(OrderContent *)order
{
    [super setCell:cell withData:order];

    //1, create right menu buttons
    NSArray *operateMenuBtnModels = [self makeCellRightButtons:order];
    cell.topContentView.userInteractionEnabled = (operateMenuBtnModels.count > 0);
    [cell setRightButtonsWithModels:operateMenuBtnModels];

    //2, set cell subviews layout
    [self setCellLayoutType:cell];

    //3, set data to cell
    [OrderTableViewCellDataSetter setOrderContentModel:(OrderContentModel*)order toCell:cell];
}

#pragma mark - set cell's layout type

- (void)setCellLayoutType:(OrderTableViewCell*)cell
{
    kOrderItemContentViewLayoutType layoutType = kOrderItemContentViewLayoutType1;
    
    switch (self.orderStatus) {
        case kFacilitatorOrderStatusNew:
        case kFacilitatorOrderStatusReceived:
            layoutType = kOrderItemContentViewLayoutType1;
            break;
        case kFacilitatorOrderStatusAssigned:
        case kFacilitatorOrderStatusRefused:
        case kFacilitatorOrderStatusAppointFailure:
        case kFacilitatorOrderStatusWaitForAppointment:
            layoutType = kOrderItemContentViewLayoutType2;
            break;
        case kFacilitatorOrderStatusAppointed:
        case kFacilitatorOrderStatusWaitForExecution:
        case kFacilitatorOrderStatusUnfinish:
            layoutType = kOrderItemContentViewLayoutType6;
            break;
        case kFacilitatorOrderStatusFinished:
            layoutType = kOrderItemContentViewLayoutType5;
            break;
        default:
            break;
    }
    
    cell.topOrderContentView.layoutType = layoutType;
}

#pragma mark - make cell's right menu buttons

- (NSMutableArray*)makeCellRightButtons:(OrderContent*)order
{
    NSMutableArray *operateMenuBtnModels = [[NSMutableArray alloc]init];
    BOOL showView = YES;
    MenuButtonModel *menuBtnModel;
    OrderContentModel *orderContent = (OrderContentModel *)order;
    
    switch (self.orderStatus) {
        case kFacilitatorOrderStatusNew:
        {
            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeAgree];
            [operateMenuBtnModels addObject:menuBtnModel];
            
            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeRefuse];
            [operateMenuBtnModels addObject:menuBtnModel];
        }
            break;
        case kFacilitatorOrderStatusReceived:
        {
            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeAssign];
            [operateMenuBtnModels addObject:menuBtnModel];
        }
            break;
        case kFacilitatorOrderStatusAssigned:
        case kFacilitatorOrderStatusRefused:
        case kFacilitatorOrderStatusAppointed:
        case kFacilitatorOrderStatusAppointFailure:
        case kFacilitatorOrderStatusUnfinish:
        {
            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeReassign];
            [operateMenuBtnModels addObject:menuBtnModel];
        }
            break;
        case kFacilitatorOrderStatusWaitForAppointment:
        {
            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeAppointment];
            [operateMenuBtnModels addObject:menuBtnModel];
            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeReassign];
            [operateMenuBtnModels addObject:menuBtnModel];
        }
            break;
        case kFacilitatorOrderStatusWaitForExecution:
        {
            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeSpecialFinish];
            [operateMenuBtnModels addObject:menuBtnModel];

            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeExecute];
            [operateMenuBtnModels addObject:menuBtnModel];

            menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeChangeAppointment];
            [operateMenuBtnModels addObject:menuBtnModel];
        }
            break;
        case kFacilitatorOrderStatusFinished:
        {
            if ([orderContent.partner_fwg isEqualToString:self.user.userId]) {
                menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeExtend];
                [operateMenuBtnModels addObject:menuBtnModel];

                if (1 == [orderContent.weChatVisit integerValue]
                    && 0 == [orderContent.isComment integerValue]) {
                    //微信点评但未点评
                    menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeUserComment];
                    [operateMenuBtnModels addObject:menuBtnModel];
                }
            }
        }
            break;
        case kFacilitatorOrderStatusAppointTrace:
            break;
        default:
            break;
    }
    
    if (showView) {
        menuBtnModel = [self makeMenuButtonModel:kOrderOperationTypeView];
        [operateMenuBtnModels addObject:menuBtnModel];
    }
    return operateMenuBtnModels;
}


@end
