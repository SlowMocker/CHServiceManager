//
//  DataModelEntities.h
//  HouseMarket
//
//  Created by wangzhi on 15-2-11.
//  Copyright (c) 2015年 wangzhi. All rights reserved.
//

// 所有从服务器上获取的数据模型


#import <Foundation/Foundation.h>
#import "ConfigItemInfo.h"

/**
 *  数据实体类
 */

#pragma mark - Part 1 , Common Entities

@interface StreetInfo : NSObject
@property(nonatomic, copy)NSString *street;//街道
@end

//备件信息
@interface PartsContentInfo : NSObject
@property(nonatomic, strong)NSObject *partsMainInfo;//备件主数据表对象
@property(nonatomic, copy)NSString *parts_bominfo_id;//备件bom表id
@property(nonatomic, copy)NSString *Id;//备件主数据表id
@property(nonatomic, copy)NSString *product_id;//物料代码
@property(nonatomic, copy)NSString *short_text;//产品描述
@property(nonatomic, copy)NSString *zz0010;//索赔件
@property(nonatomic, copy)NSString *zz0011;//关键件
@property(nonatomic, copy)NSString *zz0017;
@property(nonatomic, copy)NSString *zz0018;
@end

//备件信息
@interface PartMaintainContent : NSObject
@property(nonatomic, copy)NSString *object_id;//工单号
@property(nonatomic, copy)NSString *dispatch_parts_id;//备件?
@property(nonatomic, copy)NSString *parts_bominfo_id;//备件bom表id
@property(nonatomic, copy)NSString *parts_maininfo_id;//备件主数据表id

@property(nonatomic, copy)NSString *puton_part_matno;//换上件ID
@property(nonatomic, copy)NSString *part_text;//换上件名称
@property(nonatomic, copy)NSString *puton_part_number;//换上件数量
@property(nonatomic, copy)NSString *puton_status;//换上件,申请状态(1创建，2申请,3doa)

@property(nonatomic, copy)NSString *putoff_status;//换下件,申请状态(默认1创建)
@property(nonatomic, copy)NSString *putoff_part_matno;//换下件ID
@property(nonatomic, copy)NSString *putoff_part_number;//换下件数量
@property(nonatomic, copy)NSString *putoff_part_text;//换下件名称

@property(nonatomic, copy)NSString *is_send_crm; //是否已同步到CRM,1未同步，2已同步

//local
@property(nonatomic, assign, readonly)BOOL bAffectPerformOrder; //是否影响完工
@end

@class LetvProductModelDes;
@class SmartMiProductModelDes;
//机型描述
@interface ProductModelDes : NSObject
@property(nonatomic, copy)NSString *zz0018;//品牌
@property(nonatomic, copy)NSString *zzfld000003;//产品大类
@property(nonatomic, copy)NSString *zz0017;//品类
@property(nonatomic, copy)NSString *product_id;//机型代码
@property(nonatomic, copy)NSString *short_text;//机型描述
-(instancetype)initWithLetv:(LetvProductModelDes*)letvProductModel;
- (instancetype) initWithSmartMi:(SmartMiProductModelDes *)smartMiProductModel;
@end

@class LetvEmployeeInfo;
@interface EmployeeInfo : NSObject
@property(nonatomic, copy)NSString *supportman_id;
@property(nonatomic, copy)NSString *supportman_name;
@property(nonatomic, copy)NSString *supportman_phone;
@property(nonatomic, copy)NSString *supportman_type;
@property(nonatomic, copy)NSString *supporttask_total;
-(instancetype)initWithLetv:(LetvEmployeeInfo*)letvEmployee;
@end

@class LetvRepairerInfo;
@class SmartMiRepairerInfo;
@interface RepairerInfo : NSObject
@property(nonatomic, copy)NSString *customer_la;
@property(nonatomic, copy)NSString *customer_lo;
@property(nonatomic, copy)NSString *repairman_lo;
@property(nonatomic, copy)NSString *repairman_la;
@property(nonatomic, copy)NSString *repairman_address;
@property(nonatomic, copy)NSString *repairman_id;
@property(nonatomic, copy)NSString *repairman_name;
@property(nonatomic, copy)NSString *repairman_phone;
@property(nonatomic, copy)NSString *tasktotal;
-(instancetype)initWithLetvRepairerInfo:(LetvRepairerInfo*)letvRepairer;
- (instancetype) initWithSmartMiRepairerInfo:(SmartMiRepairerInfo*)smRepairer;
@end

@interface MyRepairerBaseInfo : NSObject
@property(nonatomic, copy)NSString *Id;
@property(nonatomic, copy)NSString *realname;
@property(nonatomic, copy)NSString *telephone;
@property(nonatomic, copy)NSString *userid;
@end

@interface BulletinInfo : NSObject
@property(nonatomic, copy)NSString *noticeId;//主键ID
@property(nonatomic, copy)NSString *title;//公告标题
@property(nonatomic, copy)NSString *publisher;//公告发布者
@property(nonatomic, copy)NSString *summary;//公告摘要,内容前100个字符
@property(nonatomic, copy)NSString *content;//公告内容
@property(nonatomic, copy)NSNumber *top;//是否置顶,true置顶;false反之
@property(nonatomic, copy)NSString *createTime;//公告发布时间yyyyMMddHHmmss

//local
@property(nonatomic, assign)BOOL isTop; //是否置顶，同top
@property(nonatomic, copy)NSString *createTimeText; //可读的时间文本
@end

@interface OrderContent : NSObject
@end

@class LetvSupporterOrderContent;
//技术支持工单
@interface SupporterOrderContent : OrderContent
@property(nonatomic, copy)NSString *acceptTime;//接受时间YYYYMMDDhhmmss
@property(nonatomic, copy)NSString *applyTime;//申请时间YYYYMMDDhhmmss
@property(nonatomic, copy)NSString *confirmTime;//确认时间YYYYMMDDhhmmss
@property(nonatomic, copy)NSString *content;//描述
@property(nonatomic, copy)NSString *score;//评分
@property(nonatomic, copy)NSString *status;//状态
@property(nonatomic, copy)NSString *Id; //技术支持表id
@property(nonatomic, copy)NSString *supporterId;//技术支持id
@property(nonatomic, copy)NSString *supporterName;//技术支持姓名
@property(nonatomic, copy)NSString *supporterPhone;//技术支持电话
@property(nonatomic, copy)NSString *workerId;//维修工id
@property(nonatomic, copy)NSString *workerName;//维修工姓名
@property(nonatomic, copy)NSString *workerPhone;//维修工电话
@property(nonatomic, copy)NSString *dispatch_id;
@property(nonatomic, copy)NSString *objectId;//工单号
@property(nonatomic, copy)NSString *regiontxt;//省
@property(nonatomic, copy)NSString *city1;//市
@property(nonatomic, copy)NSString *city2;//区县
@property(nonatomic, copy)NSString *street;//街道
@property(nonatomic, copy)NSString *str_suppl1;//详细地址
@property(nonatomic, copy)NSString *zzfld000000;//品牌
@property(nonatomic, copy)NSString *zzfld000003;//产品大类
@property(nonatomic, copy)NSString *zzfld000001;//品类
@property(nonatomic, copy)NSString *zzfld00000q;//机型
@property(nonatomic, copy)NSString *order_type;//工单类型
-(instancetype)initWithLetv:(LetvSupporterOrderContent*)supportInfo;

@property(nonatomic, copy)NSString *customerFullAddress;
@end

//order content model
@interface OrderContentModel : OrderContent
@property(nonatomic, copy)NSString *city1;
@property(nonatomic, copy)NSString *city2;
@property(nonatomic, copy)NSString *date_cr;
@property(nonatomic, copy)NSString *date_dy;
@property(nonatomic, copy)NSString *date_pg;
@property(nonatomic, copy)NSString *date_yy;//预约时间
@property(nonatomic, copy)NSString *date_yywc;
@property(nonatomic, copy)NSString *last_yy_time; //预约操作时间
@property(nonatomic, copy)NSString *date_gy;
@property(nonatomic, copy)NSString *date_gywc;
@property(nonatomic, copy)NSString *object_id;
@property(nonatomic, copy)NSString *partner_fwg;
@property(nonatomic, copy)NSString *partner_fwgname;
@property(nonatomic, copy)NSString *priority;
@property(nonatomic, copy)NSString *process_type;
@property(nonatomic, copy)NSString *regiontxt;
@property(nonatomic, copy)NSString *status;
@property(nonatomic, copy)NSString *str_suppl1;
@property(nonatomic, copy)NSString *street;
@property(nonatomic, copy)NSString *urgeflag;
@property(nonatomic, assign)NSInteger urgetimes;
@property(nonatomic, copy)NSString *wxg_isreceive;//维修工是否接受工单（0：未处理；1：已接受；2：拒绝）
@property(nonatomic, strong)NSNumber *yy_operate_time;
@property(nonatomic, copy)NSString *zzfld000000;
@property(nonatomic, copy)NSString *zzfld000001;
@property(nonatomic, copy)NSString *zzfld000003;
@property(nonatomic, copy)NSString *zzfld00000q;
@property(nonatomic, copy)NSString *custname;
@property(nonatomic, copy)NSString *telnumber;
@property(nonatomic, copy)NSString *supportStatus; //技术支持状态

@property(nonatomic, copy)NSString *source; //信息来源
@property(nonatomic, copy)NSNumber *weChatVisit;//微信回访（0：否；1：是）
@property(nonatomic, strong)NSNumber *isComment;//是否点评（0：否；1：是）
@property(nonatomic, strong)NSNumber *starLevel;//星级
@property(nonatomic, copy)NSString *comment;//评语

//local
@property(nonatomic, copy)NSString *customerFullAddress;

@property(nonatomic, strong)NSArray *orderStatusSet;//所属状态集
- (BOOL)isOrderStatus:(NSInteger)orderStatus; //是否属于某状态
@end

@interface OrderContentDetails : NSObject
@property(nonatomic, copy)NSString *Id; //工单主键ID
@property(nonatomic, copy)NSString *object_id; //工单ID
@property(nonatomic, copy)NSString *buytime;    //yyyyMMdd
@property(nonatomic, copy)NSString *city1;
@property(nonatomic, copy)NSString *city2;
@property(nonatomic, copy)NSString *custname;
@property(nonatomic, copy)NSString *date_cr;
@property(nonatomic, copy)NSString *date_dy;
@property(nonatomic, copy)NSString *date_pg;
@property(nonatomic, copy)NSString *date_yy;
@property(nonatomic, copy)NSString *date_gy;
@property(nonatomic, copy)NSString *date_yywc;
@property(nonatomic, copy)NSString *last_yy_time;
@property(nonatomic, copy)NSString *date_gywc;
@property(nonatomic, copy)NSString *Description;
@property(nonatomic, copy)NSString *imageuploadpath;
@property(nonatomic, copy)NSString *isBake;
@property(nonatomic, copy)NSString *isSupport;
@property(nonatomic, copy)NSString *supporterName;
@property(nonatomic, copy)NSString *isturnovercontract;
@property(nonatomic, copy)NSString *isupload;
@property(nonatomic, copy)NSString *jd_thj;
@property(nonatomic, copy)NSString *machinemodel;  //主机条码
@property(nonatomic, copy)NSString *machinemodel2;  //附机条码
@property(nonatomic, copy)NSString *memo;
@property(nonatomic, copy)NSString *unfinishedMemo;
@property(nonatomic, copy)NSString *partner;
@property(nonatomic, copy)NSString *partner_fwg;
@property(nonatomic, copy)NSString *partner_fwgname;
@property(nonatomic, copy)NSString *priority;
@property(nonatomic, copy)NSString *process_type;   //CODE
@property(nonatomic, copy)NSString *regiontxt;
@property(nonatomic, copy)NSString *status;
@property(nonatomic, copy)NSString *street; //Value
@property(nonatomic, copy)NSString *streetCode;
@property(nonatomic, copy)NSString *syscontractno;
@property(nonatomic, copy)NSString *telnumber;
@property(nonatomic, copy)NSString *wxg_isreceive; //维修工是否接受工单（0：未处理；1：已接受；2：拒绝）
@property(nonatomic, copy)NSString *zzfld0000;//销售活动
@property(nonatomic, copy)NSString *zzfld0001;//活动内容
@property(nonatomic, copy)NSString *zzfld0001xq;//活动内容详情
@property(nonatomic, copy)NSString *installExplain;//安装说明
@property(nonatomic, copy)NSString *str_suppl1;//详细地址
@property(nonatomic, copy)NSString *zzfld000000;//品牌
@property(nonatomic, copy)NSString *zzfld000003;//产品大类
@property(nonatomic, copy)NSString *zzfld000001;//品类
@property(nonatomic, copy)NSString *zzfld000002;//保内外标志
@property(nonatomic, copy)NSString *zzfld00000q;//机型
@property(nonatomic, copy)NSString *zzfld00002i;//购买日期
@property(nonatomic, copy)NSString *zzfld00000b;//主机条码
@property(nonatomic, copy)NSString *zzfld00000e;//门店名称
@property(nonatomic, copy)NSString *zzfld00002h;//故障处理
@property(nonatomic, copy)NSString *zzfld00005y;//故障处理方式及部位
@property(nonatomic, copy)NSString *zzfld000005;//预约未成功原因(代码)
@property(nonatomic, copy)NSString *zzfld00000m;//电商订单号
@property(nonatomic, copy)NSObject *frequency;  //预约情况
@property(nonatomic, strong)NSArray *tDispatchParts;//item: PartMaintainContent
@property(nonatomic, strong)SupporterOrderContent *supportInfo;

//微信点评
@property(nonatomic, strong)NSNumber *weChatVisit;//微信回访（0：否；1：是）
@property(nonatomic, copy)NSString *deviceImgUrl;//设备图片地址
@property(nonatomic, copy)NSString *invoiceImgUrl;//发票图片地址
@property(nonatomic, strong)NSNumber *isComment;//是否点评（0：否；1：是）
@property(nonatomic, strong)NSNumber *starLevel;//星级
@property(nonatomic, copy)NSString *comment;//评语
@property(nonatomic, strong)NSNumber *isIntroduce;//已介绍清洗服务（0：否；1：是）
@property(nonatomic, strong)NSNumber *isDemonstrate;//已演示电视网络功能（0：否；1：是）

//服务改善
@property(nonatomic, copy)NSString *infosource;//信息来源
@property(nonatomic, copy)NSString *improve;//服务改善原因

//延保
@property(nonatomic, copy)NSString *extendprdId; //延保合同id
@property(nonatomic, copy)NSString *extendprdType;
@property(nonatomic, copy)NSString *extendprdContractNum;
@property(nonatomic, copy)NSString *extendprdStatus;
@property(nonatomic, copy)NSString *failId; //未完工原因ID

//local added
@property(nonatomic,assign)BOOL isAirConditioning;
@property(nonatomic,assign)BOOL isTV;
@property(nonatomic, copy)NSString *brandIdStr;
@property(nonatomic, copy)NSString *productIdStr;
@property(nonatomic, copy)NSString *categroyIdStr;
@property(nonatomic, readonly)kProductType productType;
@property(nonatomic, copy)NSString *customerFullCountyAddress;
@property(nonatomic, copy)NSString *customerFullAddress;
@end

@interface OrderTraceInfos: NSObject
@property(nonatomic, copy)NSString *dispatchparts_id;
@property(nonatomic, copy)NSString *object_id;
@property(nonatomic, copy)NSString *puton_part_matno;
@property(nonatomic, copy)NSString *puton_status;
@property(nonatomic, copy)NSString *wlmc;   //物料名称
@property(nonatomic, copy)NSString *zzfld00002s;    //备件条码
@property(nonatomic, copy)NSString *refusalReason;//未审核通过原因
@end

@class LetvSellFeeListInfos;
@interface SellFeeListInfos: NSObject
@property(nonatomic, copy)NSNumber *Id;    //费用表ID，主键,long
@property(nonatomic, copy)NSString *objectId; //工单表objectid
@property(nonatomic, copy)NSNumber *dispatchId;//工单表ID, long
@property(nonatomic, copy)NSNumber *createTime; //创建时间, long
@property(nonatomic, copy)NSString *isSendtoCrm;//同步到CRM,1已同步，0未同步
@property(nonatomic, copy)NSString *itmType; //保外费用：ZRVW:智能产品：ZPRV
@property(nonatomic, copy)NSNumber *netValue; //金额, double
@property(nonatomic, copy)NSString *orderedProd; //保外.服务物料代码(智能.产品代码)
@property(nonatomic, copy)NSString *prodDescription; //智能产品描述
@property(nonatomic, copy)NSNumber *quantity; //数量, long
@property(nonatomic, copy)NSString *zzfld00002v; //收据号
@property(nonatomic, copy)NSString *zzfld00005e; //智能产品分类

//local
@property(nonatomic, copy)NSString *brandIdStr;
@property(nonatomic, copy)NSString *categoryIdStr;
@property(nonatomic, readonly)CGFloat totalPrice;

-(instancetype)initWithLetvSellFeeListInfos:(LetvSellFeeListInfos*)info;
@end

@interface DeviceInfos : NSObject
@property(nonatomic, copy)NSString *zzfld00002i;//购买日期YYYYMMDD
@property(nonatomic, copy)NSString *zzfld00000e;//购机商场
@property(nonatomic, copy)NSString *barCode;//机号条码
@property(nonatomic, copy)NSString *mainboardCode;//主板物料代码
@property(nonatomic, copy)NSString *mainboardDesc;//主板物料描述
@property(nonatomic, copy)NSString *powerCode;//电源物料编码
@property(nonatomic, copy)NSString *powerDesc;//电源物料描述
@property(nonatomic, copy)NSString *screenFactory;   //屏厂家
@property(nonatomic, copy)NSString *screenType; //屏型号
@end

@interface CHIQYunAirConditioningInfos : NSObject
@property(nonatomic, copy)NSString *acModel;
@property(nonatomic, copy)NSString *compNoRadiatorCode;
@property(nonatomic, copy)NSString *compNoRadiatorName;
@property(nonatomic, copy)NSString *compRadiatorCode;
@property(nonatomic, copy)NSString *compRadiatorName;
@property(nonatomic, copy)NSString *compressorCode;
@property(nonatomic, copy)NSString *compressorName;
@property(nonatomic, copy)NSString *dcFanDriCode;
@property(nonatomic, copy)NSString *dcFanDriName;
@property(nonatomic, copy)NSString *dispSwitchCode;
@property(nonatomic, copy)NSString *dispSwitchName;
@property(nonatomic, copy)NSString *dispWareCode;
@property(nonatomic, copy)NSString *dispWareName;
@property(nonatomic, copy)NSString *gasSensorCode;
@property(nonatomic, copy)NSString *gasSensorName;
@property(nonatomic, copy)NSString *inBoardCode;
@property(nonatomic, copy)NSString *inBoardName;
@property(nonatomic, copy)NSString *inFanCode;
@property(nonatomic, copy)NSString *inFanName;
@property(nonatomic, copy)NSString *inPanSensorCode;
@property(nonatomic, copy)NSString *inPanSensorName;
@property(nonatomic, copy)NSString *inTempSensorCode;
@property(nonatomic, copy)NSString *inTempSensorName;
@property(nonatomic, copy)NSString *infraredWareCode;
@property(nonatomic, copy)NSString *infraredWareName;
@property(nonatomic, copy)NSString *lightWareCode;
@property(nonatomic, copy)NSString *lightWareName;
@property(nonatomic, copy)NSString *outBoardCode;
@property(nonatomic, copy)NSString *outBoardName;
@property(nonatomic, copy)NSString *outFanCode;
@property(nonatomic, copy)NSString *outFanName;
@property(nonatomic, copy)NSString *outPanSensorCode;
@property(nonatomic, copy)NSString *outPanSensorName;
@property(nonatomic, copy)NSString *outSensorCode;
@property(nonatomic, copy)NSString *outSensorName;
@property(nonatomic, copy)NSString *socPowerCode;
@property(nonatomic, copy)NSString *socPowerName;
@property(nonatomic, copy)NSString *socWareCode;
@property(nonatomic, copy)NSString *socWareName;
@end

//延保客户
@interface ExtendCustomerInfo : NSObject
@property(nonatomic, copy)NSString *Id;//客户id
@property(nonatomic, copy)NSString *cusName;//	客户姓名
@property(nonatomic, copy)NSString *province;//省
@property(nonatomic, copy)NSString *city;//市
@property(nonatomic, copy)NSString *town;//区
@property(nonatomic, copy)NSString *street;//街道code
@property(nonatomic, copy)NSString *streetValue;//街道value
@property(nonatomic, copy)NSString *detailAddress;//详细地址
@property(nonatomic, copy)NSString *cusTelNumber;//	客户电话
@property(nonatomic, copy)NSString *cusMobNumber;//客户移动电话
@property(nonatomic, copy)NSString *extendprdId;//延保id
@end

//延保单内容
@interface ExtendServiceOrderContent : NSObject
@property(nonatomic, copy)NSString *Id;//延保id
@property(nonatomic, copy)NSString *status;//	状态
@property(nonatomic, copy)NSString *objectId;//	工单号
@property(nonatomic, copy)NSString *type;//	类型1单品延保，2家多保
@property(nonatomic, copy)NSString *userId;//	维修工userid
@property(nonatomic, copy)NSString *serverId;//	创建用户服务商id
@property(nonatomic, copy)NSString *reason;//	成交原因（代码）
@property(nonatomic, copy)NSString *contractNum;//	合同号
@property(nonatomic, strong)NSNumber *signDate;//	签字日期
@property(nonatomic, copy)NSString *extendLife;//	延保年限
@property(nonatomic, copy)NSString *Description;//	合同描述
@property(nonatomic, copy)NSString *sysContractNum;//	订单号
@property(nonatomic, copy)NSString *creatTime;//	创建时间
@property(nonatomic, copy)NSString *updateTime;//	更新时间
@property(nonatomic, copy)NSString *zsp00180;//	服务商id
@property(nonatomic, copy)NSString *zsp00170;//	操作人id
@property(nonatomic, copy)NSString *tempNum;//临时延保号
@property(nonatomic, copy)NSNumber *econtract;//电子合同（0：否；1：是）
@property(nonatomic, copy)NSNumber *isPay;//是否支付（0：否；1：是）
@property(nonatomic, copy)NSString *payAmount;//支付金额

@property(nonatomic, copy)NSString *productCount;//	产品数量
@property(nonatomic, strong)NSArray *productInfoList;// item : ExtendProductContent
@property(nonatomic, strong)ExtendCustomerInfo *customerInfo;

//local
@property(nonatomic, assign, readonly)BOOL editable;
@end

//延保产品
@interface ExtendProductContent : NSObject
@property(nonatomic, copy)NSString *zzfld000000;//品牌
@property(nonatomic, copy)NSString *zzfld000003v;//其它品牌
@property(nonatomic, copy)NSString *zzfld000001;//品类(机器类型)
@property(nonatomic, copy)NSString *zzfld00000q;//机型
@property(nonatomic, copy)NSString *zzfld00005j;//机型描述,或手动输入的机型
@property(nonatomic, strong)NSString *zzfld00002i;//购买日期,in:yyyy-mm-dd,out: timeinteval
@property(nonatomic, copy)NSString *zzfld00000b;//机号(主机/内机条码)
@property(nonatomic, strong)NSString *buyprice;//购机价格,in: string, out:number
@property(nonatomic, copy)NSString *pricerange;//价格区间
@property(nonatomic, copy)NSString *factoryWarrantyDue;//厂保到期日期yyyy-MM-dd
@property(nonatomic, copy)NSString *invoiceNo;//发票号
@property(nonatomic, copy)NSString *extendprdBeginDue;//延保开始日期
@property(nonatomic, copy)NSString *extendprdEndDue;//延保结束日期
@property(nonatomic, copy)NSString *zzfld00000e;//购机门店
@end

@interface AppVersionInfo : NSObject
@property(nonatomic, copy)NSString *Id;//	应用id
@property(nonatomic, copy)NSString *upgradeType;//	是否强制升级
@property(nonatomic, copy)NSString *downloadUrl;//	最新版本的跳转下载地址
@property(nonatomic, copy)NSString *number;//	版本号
@property(nonatomic, copy)NSString *entrance;//	版本入口
@property(nonatomic, copy)NSString *name;//	版本名
@property(nonatomic, copy)NSString *createTime;//	版本创建时间
@property(nonatomic, copy)NSString *updateTime;//	版本更新时间
@property(nonatomic, copy)NSString *isPublished;//	是否发布
@property(nonatomic, copy)NSString *isAvailable;//	是否可用
@property(nonatomic, copy)NSString *Description;//	版本描述
@end

@interface AdditionalBusinessItem  : NSObject
@property(nonatomic, copy)NSString *type;   //物料类别
@property(nonatomic, copy)NSString *items;  //销售物料
@property(nonatomic, copy)NSString *price;  //价格
@property(nonatomic, copy)NSString *num;    //数量
@end

#pragma mark - Part 2 , Letv Relative Entities

//order content model
@interface LetvOrderContentModel : OrderContent
@property(nonatomic, assign)NSNumber *Id;//主键ID
@property(nonatomic, copy)NSString *objectId;//订单号
@property(nonatomic, copy)NSString *status;//工单状态
@property(nonatomic, copy)NSString *createTime;//创建时间yyyyMMddHHmmss
@property(nonatomic, copy)NSString *orderType;//订单类型Code
@property(nonatomic, copy)NSString *orderTypeVal;//订单类型Val
@property(nonatomic, copy)NSString *firstApptDate;//预约日期yyyyMMddHHmmss
@property(nonatomic, copy)NSString *dispatchDate;//派工日期yyyyMMddHHmmss
@property(nonatomic, copy)NSString *aboutDate;//代约时间yyyyMMddHHmmss
@property(nonatomic, copy)NSString *province;//省
@property(nonatomic, copy)NSString *city;//市
@property(nonatomic, copy)NSString *county;//县（区）
@property(nonatomic, copy)NSString *town;//镇（乡）
@property(nonatomic, copy)NSString *street;//街道
@property(nonatomic, copy)NSString *detailAddr;//详细地址
@property(nonatomic, copy)NSString *brand;//品牌Code
@property(nonatomic, copy)NSString *brandVal;//品牌Val
@property(nonatomic, copy)NSString *productType;//产品大类Code
@property(nonatomic, copy)NSString *productTypeVal;//产品大类Val
@property(nonatomic, copy)NSString *category;//品类Code
@property(nonatomic, copy)NSString *categoryVal;//品类Val
@property(nonatomic, copy)NSString *priority;//优先级一般,紧急,重大
@property(nonatomic, copy)NSString *model;//机型Code
@property(nonatomic, copy)NSString *modelVal;//机型Val
@property(nonatomic, copy)NSString *isReceive;//维修工是否接受工单（0：未处理；1：已接受；2：拒绝）

@property(nonatomic, copy)NSString *serviceReqType;//装、修CODE
@property(nonatomic, copy)NSString *urgeFlag;//催单标记（X：催单；0或空：不催单）
@property(nonatomic, assign)NSInteger urgeTimes;//催单次数
@property(nonatomic, copy)NSString *workerId;//维修人员编号
@property(nonatomic, copy)NSString *workerName;//维修人员名字
@property(nonatomic, copy)NSString *name;//客户姓名
@property(nonatomic, copy)NSString *phoneNum;//客户电话号码
@property(nonatomic, copy)NSString *lastApptDate;//最后一次预约日期
@property(nonatomic, copy)NSString *firstApptOpDate;//首次预约操作日期
@property(nonatomic, copy)NSString *lastApptOpDate;//最后一次预约操作日期
@property(nonatomic, copy)NSString *dispatchLogLastApptDate;//工单日志中记录的最后一次预约日期
@property(nonatomic, copy)NSString *supprotStatus;//技术支持状态（101:申请；102:接受；103:确认）
@property(nonatomic, copy)NSString *customerFullAddress;

@property(nonatomic, strong)NSArray *orderStatusSet; //所属的状态集
- (BOOL)isOrderStatus:(NSInteger)orderStatus;
@end

@interface LetvOrderContentDetails : NSObject

//summary info
@property(nonatomic, assign)NSNumber *Id;//主键ID
@property(nonatomic, copy)NSString *objectId;//订单号
@property(nonatomic, copy)NSString *status;//工单状态
@property(nonatomic, copy)NSString *createTime;//创建时间yyyyMMddHHmmss
@property(nonatomic, copy)NSString *orderType;//订单类型Code
@property(nonatomic, copy)NSString *orderTypeVal;//订单类型Val
@property(nonatomic, copy)NSString *firstApptDate;//预约日期yyyyMMddHHmmss
@property(nonatomic, copy)NSString *dispatchDate;//派工日期yyyyMMddHHmmss
@property(nonatomic, copy)NSString *aboutDate;//代约时间yyyyMMddHHmmss
@property(nonatomic, copy)NSString *province;//省
@property(nonatomic, copy)NSString *city;//市
@property(nonatomic, copy)NSString *county;//县（区）
@property(nonatomic, copy)NSString *town;//镇（乡）
@property(nonatomic, copy)NSString *street;//街道
@property(nonatomic, copy)NSString *detailAddr;//详细地址
@property(nonatomic, copy)NSString *brand;//品牌Code
@property(nonatomic, copy)NSString *brandVal;//品牌Val
@property(nonatomic, copy)NSString *productType;//产品大类Code
@property(nonatomic, copy)NSString *productTypeVal;//产品大类Val
@property(nonatomic, copy)NSString *category;//品类Code
@property(nonatomic, copy)NSString *categoryVal;//品类Val
@property(nonatomic, copy)NSString *priority;//优先级一般,紧急,重大
@property(nonatomic, copy)NSString *model;//机型Code
@property(nonatomic, copy)NSString *modelVal;//机型Val
@property(nonatomic, copy)NSString *isReceive;//维修工是否接受工单（0：未处理；1：已接受；2：拒绝）
@property(nonatomic, copy)NSString *urgeFlag;//催单标记（X：催单；0或空：不催单）
@property(nonatomic, copy)NSString *urgeTimes;//催单次数
@property(nonatomic, copy)NSString *workerId;//维修人员编号
@property(nonatomic, copy)NSString *workerName;//维修人员名字
@property(nonatomic, copy)NSString *name;//客户姓名
@property(nonatomic, copy)NSString *phoneNum;//客户电话号码
@property(nonatomic, copy)NSString *lastApptDate;//最后一次预约日期
@property(nonatomic, copy)NSString *firstApptOpDate;//首次预约操作日期
@property(nonatomic, copy)NSString *lastApptOpDate;//最后一次预约操作日期
@property(nonatomic, copy)NSString *dispatchLogLastApptDate;//工单日志中记录的最后一次预约日期
@property(nonatomic, copy)NSString *supprotStatus;//技术支持状态（101:申请；102:接受；103:确认）
@property(nonatomic, copy)NSString *customerFullAddress;
@property(nonatomic, copy)NSString *customerFullCountyAddress; //省市县

//more info
@property(nonatomic, copy)NSString *letvOrderNum;//乐视工单编号（乐视单号）
@property(nonatomic, copy)NSString *serviceReqType;//服务请求类型
@property(nonatomic, copy)NSString *serviceItems;//服务项目
@property(nonatomic, copy)NSString *serverId;//服务商编号
@property(nonatomic, copy)NSString *memo;//备注
@property(nonatomic, copy)NSString *apptMemo;//预约备注
@property(nonatomic, copy)NSString *apptFailCause;//预约未成功原因(代码)
@property(nonatomic, copy)NSString *statusL1;//一级工单状态
@property(nonatomic, copy)NSString *statusL2;//二级工单状态
@property(nonatomic, copy)NSString *handleResult;//处理结果
@property(nonatomic, copy)NSString *vipCardActive;//会员卡激活（0：否；1：是）
@property(nonatomic, copy)NSString *notActiveCause;//未激活原因
@property(nonatomic, copy)NSString *isBack;//是否打回标识(0：否；1：是)
@property(nonatomic, copy)NSString *streetCode;//街道代码
@property(nonatomic, copy)NSString *securityLabe;//保内外标志（产品质保）
@property(nonatomic, copy)NSString *securityLabeVal;//保内外标志（产品质保）属性名
@property(nonatomic, copy)NSString *faultDesc;//故障现象
@property(nonatomic, copy)NSString *faultHandling;//故障处理(或维修措施)
@property(nonatomic, copy)NSString *snCode;//SN编码
@property(nonatomic, copy)NSString *macAddress;//MAC地址
@property(nonatomic, copy)NSString *buyDate;//购机日期yyyyMMdd
@property(nonatomic, copy)NSString *installWay;//安装方式
@property(nonatomic, copy)NSString *isBearingWall;//是否承重墙
@property(nonatomic, copy)NSString *isBuyRack;//是否购买挂架（是否官方购买挂架）
@property(nonatomic, copy)NSString *network;//家庭网络环境
@property(nonatomic, copy)NSString *invoiceNum;//发票号（发票）
@property(nonatomic, copy)NSString *faultCode;//故障代码
@property(nonatomic, copy)NSString *faultCodeVal;//故障代码VAL
@property(nonatomic, copy)NSString *replPartsName;//更换备件名称
@property(nonatomic, copy)NSString *isSupport;//是否需要技术支持(0：不需要支持；1：需要支持)
@property(nonatomic, copy)NSString *supporterId;//技术支持人员编号
@property(nonatomic, copy)NSString *supporterName;//技术支持人员姓名
@property(nonatomic, copy)NSString *supporterPhone;//技术支持人员电话
@property(nonatomic, copy)NSString *supportInfoId;//技术支持表主键ID
@property(nonatomic, copy)NSString *applyTime;//申请时间
@property(nonatomic, copy)NSString *acceptTime;//接受时间
@property(nonatomic, copy)NSString *confirmTime;//确认时间
@property(nonatomic, copy)NSString *score;//评分
@property(nonatomic, copy)NSString *content;//内容描述

//locate
@property(nonatomic, strong)SupporterOrderContent *supportInfo;
@property(nonatomic, copy)NSString *serviceReqTypeVal;
@end

@interface LetvRepairerInfo : NSObject
@property(nonatomic, copy)NSString *repairManId;//维修人员编号
@property(nonatomic, copy)NSString *repairManName;//维修人员姓名
@property(nonatomic, copy)NSString *repairManTel;//维修人员电话
@property(nonatomic, copy)NSString *repairManAddr;//维修人员地址
@property(nonatomic, copy)NSString *customerLon;//客户经度
@property(nonatomic, copy)NSString *customerLat;//客户纬度
@end

//机型描述
@interface LetvProductModelDes : NSObject
@property(nonatomic, copy)NSString *brand;//品牌
@property(nonatomic, copy)NSString *model;//机型代码
@property(nonatomic, copy)NSString *modelDesc;//机型描述
@property(nonatomic, copy)NSString *category;//品类
@property(nonatomic, copy)NSString *productType;//产品大类
@end

@interface LetvEmployeeInfo : NSObject
@property(nonatomic, copy)NSString *supporterId;//技术支持人员编号
@property(nonatomic, copy)NSString *supporterName;//技术支持人员姓名
@property(nonatomic, copy)NSString *supporterPhone;//技术支持人员电话
@property(nonatomic, copy)NSString *supporterType;//技术支持人员类型
@property(nonatomic, copy)NSString *supportTaskNum;//技术支持人员待处理任务数
@end

@interface LetvSellFeeListInfos : NSObject
@property(nonatomic, copy)NSNumber *Id;//主键ID
@property(nonatomic, copy)NSNumber *dispatchInfoId;//工单表主键ID
@property(nonatomic, copy)NSString *objectId;//工单号
@property(nonatomic, copy)NSNumber *createTime;//创建时间
@property(nonatomic, copy)NSString *isSend2Crm;//是否同步CRM（1:是,0:否）
@property(nonatomic, copy)NSString *itmType;//项目类别（ZPRV：智能产品行项目；ZRV1：费用行项目。）
@property(nonatomic, copy)NSString *bomCode;//物料代码（产品代码）
@property(nonatomic, copy)NSString *Description;//描述（产品描述）
@property(nonatomic, copy)NSString *handleCode;//处理代码
@property(nonatomic, copy)NSString *letvCode;//乐视代码
@property(nonatomic, copy)NSString *letvCodeName;//乐视代码名称
@property(nonatomic, copy)NSString *softwareVersion;//软件版本
@property(nonatomic, copy)NSString *contractNum;//延保合同号
@property(nonatomic, copy)NSNumber *quantity;//数量
@property(nonatomic, copy)NSNumber *unitPrice;//单价
@property(nonatomic, copy)NSString *receiptNum;//收据号
@property(nonatomic, copy)NSString *classify;//智能产品分类

//local
@property(nonatomic, copy)NSString *brandIdStr;
@property(nonatomic, copy)NSString *categoryIdStr;
@property(nonatomic, readonly)CGFloat totalPrice;
@end

@interface LetvBomContent : NSObject
@property(nonatomic, copy)NSString *bomCode;//物料代码
@property(nonatomic, copy)NSString *bomDesc;//物料代码描述
@property(nonatomic, copy)NSString *letvCode;// 乐视代码
@property(nonatomic, copy)NSString *letvCodeName;// 乐视代码名称
@end

@interface LetvSupporterOrderContent : OrderContent
@property(nonatomic, copy)NSString *Id;//技术支持信息主键ID
@property(nonatomic, copy)NSString *status;//状态（101:申请；102:接受；103:确认）
@property(nonatomic, copy)NSString *acceptTime;//接受时间YYYYMMDDhhmmss
@property(nonatomic, copy)NSString *applyTime;//申请时间YYYYMMDDhhmmss
@property(nonatomic, copy)NSString *confirmTime;//确认时间YYYYMMDDhhmmss
@property(nonatomic, copy)NSString *content;//内容描述
@property(nonatomic, copy)NSString *score;//评分
@property(nonatomic, copy)NSString *supporterId;//技术支持人员编号
@property(nonatomic, copy)NSString *supporterName;//技术支持人员姓名
@property(nonatomic, copy)NSString *supporterPhone;//技术支持人员电话
@property(nonatomic, copy)NSString *workerId;//维修人员编号
@property(nonatomic, copy)NSString *workerName;//维修人员姓名
@property(nonatomic, copy)NSString *workerPhone;//维修人员电话
@property(nonatomic, copy)NSString *dispatchInfoId;//工单表主键ID
@property(nonatomic, copy)NSString *objectId;//工单号
@property(nonatomic, copy)NSString *province;//省
@property(nonatomic, copy)NSString *city;//市
@property(nonatomic, copy)NSString *county;//县（区）
@property(nonatomic, copy)NSString *town;//镇（乡）
@property(nonatomic, copy)NSString *street;//街道
@property(nonatomic, copy)NSString *detailAddr;//详细地址
@property(nonatomic, copy)NSString *brand;//品牌
@property(nonatomic, copy)NSString *productType;//产品大类
@property(nonatomic, copy)NSString *category;//品类
@property(nonatomic, copy)NSString *model;//机型
@property(nonatomic, copy)NSString *orderType;//订单类型
@property(nonatomic, copy)NSString *serviceReqType;//装、修CODE
@property(nonatomic, copy)NSString *customerFullAddress;
@end

@interface OrderFilterConditionItems : NSObject
@property(nonatomic, copy)NSString *brands;
@property(nonatomic, copy)NSString *productTypes;
@property(nonatomic, copy)NSString *orderTypes;
- (void)cleanItemsData;
@end

@interface QuestionnaireSurvey : NSObject
@property(nonatomic, copy)NSString *Id; //主键ID
@property(nonatomic, copy)NSString *surveyName;//调查标题
@property(nonatomic, copy)NSString *surveyUrl;//调查url链接
@property(nonatomic, copy)NSString *startTime;//调查启用时间yyyyMMddHHmmss
@property(nonatomic, copy)NSString *endTime;//调查结束时间yyyyMMddHHmmss
@property(nonatomic, copy)NSString *enabledTime;//启用时间yyyyMMddHHmmss

//local
@property(nonatomic, copy)NSString *surveyEntityId; //模拟生成的唯一调查表ID
@end

@interface PushMessageContent : NSObject
//nil: 常规文本, '0':微信点评结果, '9':延保收款
@property(nonatomic, copy)NSString *type;
@property(nonatomic, copy)NSString *message;
@property(nonatomic, strong)NSObject *data;
@end

//延保单收款时信息
@interface ExtendOrderPaymentInfo : NSObject
@property(nonatomic, copy)NSString *code;//（0：成功；1：普通错误；2：未知错误；9：参数错误。）
@property(nonatomic, copy)NSString *msg;
@property(nonatomic, copy)NSString *url;//微信二维码URL地址
@property(nonatomic, copy)NSString *ext_po_number;//电子合同号
@property(nonatomic, copy)NSString *appid;//手机管家唯一ID（临时延保号）
@property(nonatomic, copy)NSString *price;//价格
@end