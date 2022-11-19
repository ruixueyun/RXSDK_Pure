# RXSDK_Pure
瑞雪通行SDK-iOS

##综述
关于定位
总体来说瑞雪是一个解决游戏产品通用问题的 BaaS 服务，主要通过私有化方式进行部署，即为每个项目团队都独立部署一套独占服务。

交付方式
瑞雪主要功能分为两部：ToC 的接口服务与 ToB 的管理后台，其中接口的绝大部分运行参数通过管理后台由项目团队进行配置。

为了减轻项目团队的接入成本，瑞雪也提供了各端的 SDK 实现，CP 可以通过继承 SDK 快速接入使用瑞雪的各项能力。


##初始化
•初始化用于本地保存productId、channelId、cpid、baseUrlList等数据，调用即成功。
•接口原型：

`
/**
 * 初始化SDK
 * @param productId 产品id
 * @param channelId 渠道id
 * @param cpid 客户端id
 * @param baseUrlList 请求域名队列
 */
- (void)initWithProductId:(NSString *)productId
                channelId:(NSString *)channelId
                     cpid:(NSString *)cpid
              baseUrlList:(NSArray *)baseUrlList;
`
