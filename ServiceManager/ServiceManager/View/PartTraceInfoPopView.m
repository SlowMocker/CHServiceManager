//
//  PartTraceInfoPopView.m
//  ServiceManager
//
//  Created by will.wang on 2017/1/4.
//  Copyright © 2017年 wangzhi. All rights reserved.
//

#import "PartTraceInfoPopView.h"
#import "WZModal.h"
#import "Util.h"

@interface PartTraceInfoPopView ()
@property(nonatomic, strong)UIScrollView *scrollView;
@property(nonatomic, strong)UIView *container;


@property(nonatomic, strong)UILabel *text1Label;
@property(nonatomic, strong)UILabel *text2Label;
@property(nonatomic, strong)UILabel *text3Label;
@property(nonatomic, strong)UILabel *text4Label;

@property(nonatomic, strong)UIButton *cancelButton;
@property(nonatomic, strong)UIButton *okButton;

@property(nonatomic, assign)CGFloat horizentalPadding;

@end

@implementation PartTraceInfoPopView

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.horizentalPadding = kTableViewLeftPadding;
        self.bounds = CGRectMake(0, 0, ScreenWidth - self.horizentalPadding * 2, 260);
        [self makeCustomSubViews];
        [self layoutCustomSubViews];
    }
    return self;
}

- (void)setPartInfos:(OrderTraceInfos *)partInfos{
    if (_partInfos != partInfos) {
        _partInfos = partInfos;
        [self setPartInfoToViews:_partInfos];
    }
}

- (void)setPartInfoToViews:(OrderTraceInfos*)part
{
    NSString *tempStr = nil;
    tempStr = [Util defaultStr:kUnknown ifStrEmpty:part.object_id];
    self.text1Label.text = [NSString stringWithFormat:@"工单号 : %@",tempStr];
    self.text1Label.adjustsFontSizeToFitWidth = YES;
    
    tempStr = [Util defaultStr:@"物料名称未知" ifStrEmpty:part.wlmc];
    self.text2Label.text = tempStr;
    self.text2Label.adjustsFontSizeToFitWidth = YES;
    
    tempStr = [Util defaultStr:kUnknown ifStrEmpty:part.puton_part_matno];
    self.text3Label.text = [NSString stringWithFormat:@"备件编号 : %@",tempStr];
    self.text3Label.adjustsFontSizeToFitWidth = YES;
    
    //审核未通过原因
    BOOL bRefuse = [part.puton_status isEqualToString:@"4"];
    if (bRefuse) {
        AttributeStringAttrs *titleAttr = [AttributeStringAttrs new];
        titleAttr.font = SystemFont(14);
        titleAttr.textColor = kColorBlack;
        titleAttr.text = @"审核未通过原因 ：\n\t";

        AttributeStringAttrs *reasonAttr = [AttributeStringAttrs new];
        reasonAttr.font = SystemFont(14);
        reasonAttr.textColor = kColorDarkGray;

        ConfigItemInfo *refusalReasonItem;
        if (![Util isEmptyString:part.refusalReason]) {
            refusalReasonItem = [[ConfigInfoManager sharedInstance] findConfigItemInfoByType:MainConfigInfoTableType36 code:part.refusalReason];
        }
        reasonAttr.text = [Util defaultStr:kUnknown ifStrEmpty:refusalReasonItem.value];
    
        self.text4Label.attributedText = [NSString makeAttrString:@[titleAttr, reasonAttr]];
    }else {
        self.text4Label.attributedText = nil;
    }
}

- (void)makeCustomSubViews
{
    //set set color white
    self.backgroundColor = kColorWhite;
    [self circleCornerWithRadius:10.0];
    
    _titleLabel = [self makeLabel:16 color:kColorDarkGray];
    _titleLabel.font = SystemBoldFont(16);
    _titleLabel.text = @"备件跟踪";
    _titleLabel.textAlignment = NSTextAlignmentCenter;
    [_titleLabel addLineTo:kFrameLocationBottom];
    [self addSubview:_titleLabel];
    
    _scrollView = [[UIScrollView alloc]init];
    _scrollView.showsVerticalScrollIndicator = NO;
    [self addSubview:self.scrollView];
    
    _container = [[UIView alloc]init];
    [self.scrollView addSubview:self.container];
    
    _text1Label = [self makeLabel:14 color:kColorLightOrange];
    [self.container addSubview:_text1Label];
    
    _text2Label = [self makeLabel:14 color:kColorDefaultBlue];
    [self.container addSubview:_text2Label];
    
    _text3Label = [self makeLabel:14 color:kColorDefaultGray];
    _text3Label.textColor = [UIColor purpleColor];
    [self.container addSubview:_text3Label];

    _text4Label = [self makeLabel:14 color:[UIColor grayColor]];
    _text4Label.numberOfLines = 0;
    _text4Label.lineBreakMode = NSLineBreakByCharWrapping;
    [self.container addSubview:_text4Label];

    //reset and ok buttons
    _okButton = [self makeButton:@"确 定" action:@selector(okButtonClicked:)];
    [_okButton addLineTo:kFrameLocationTop];
    [self addSubview:_okButton];
}

- (void)layoutCustomSubViews
{
    //filter grid view
    [self.titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.left.right.equalTo(self);
        make.height.equalTo(@(kButtonDefaultHeight));
    }];
    
    [self.scrollView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.equalTo(self.titleLabel.mas_bottom);
        make.left.equalTo(self).with.offset(kTableViewLeftPadding);
        make.right.equalTo(self).with.offset(-kTableViewLeftPadding);
        make.bottom.equalTo(self.okButton.mas_top);
    }];
    
    [self.container mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.scrollView);
        make.width.equalTo(self.scrollView);
    }];

    //content labels
    NSArray *labelArray = @[self.text1Label, self.text2Label, self.text3Label,self.text4Label];
    UIView *preView;
    for (UIView *lablelView in labelArray) {
        [lablelView mas_makeConstraints:^(MASConstraintMaker *make) {
            if (nil == preView) {
                make.top.equalTo(self.container);
            }else {
                make.top.equalTo(preView.mas_bottom);
            }
            make.left.equalTo(self.container);
            make.right.equalTo(self.container);

            //set single line height
            if (lablelView != self.text4Label) {
                make.height.equalTo(@(26));
            }
        }];
        preView = lablelView;
    }
    
    [self.container mas_makeConstraints:^(MASConstraintMaker *make) {
        make.bottom.equalTo(self.text4Label);
    }];

    [self.okButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.bottom.equalTo(self);
        make.height.equalTo(@(kButtonDefaultHeight));
    }];
}

- (UILabel*)makeLabel:(CGFloat)fontSize color:(UIColor*)textColor
{
    UILabel *label = [[UILabel alloc]init];
    [label clearBackgroundColor];
    label.font = SystemFont(fontSize);
    label.textColor = textColor;
    
    return label;
}

- (UIButton*)makeButton:(NSString*)title action:(SEL)action
{
    UIButton *button = [UIButton textButton:title backColor:kColorClear target:self action:action];
    button.titleLabel.font = SystemFont(15);
    [button setTitleColor:ColorWithHex(@"#007aff") forState:UIControlStateNormal];
    
    return button;
}

- (void)okButtonClicked:(UIButton*)button
{
    [self hide];
}

- (void)show
{
    WZModal *modal = [WZModal sharedInstance];
    
    if (!modal.isShowing) {
        modal.showCloseButton = NO;
        modal.tapOutsideToDismiss = NO;
        modal.onTapOutsideBlock = nil;
        modal.contentViewLocation = WZModalContentViewLocationMiddle;
        [modal showWithContentView:self andAnimated:YES];
    }
}

- (void)hide
{
    [[WZModal sharedInstance]hide];
}

@end
