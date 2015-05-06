
#define CALLBACK

typedef struct
{
}videoInfo;
typedef struct
{
}audioInfo;
typedef struct
{
}errorInfo;
typedef struct
{
}channelInfo;

typedef void (CALLBACK videoCB) (const long dataHandle, const videoInfo* vIF, const char* data, const int dataLen, void* parameter);
typedef void (CALLBACK audioCB) (const long dataHandle, const audioInfo* aIF, const char* data, const int dataLen, void* parameter);
typedef void (CALLBACK errorCB) (const long msHandle, const errorInfo* eIF, void* parameter);
typedef void (CALLBACK channelInfoCB) (const long msHandle, const channelInfo** cIFL, void* parameter);

//连接到服务器
bool Connect(long& msHandle);

//断开连接
bool Disconnect(const long msHandle);

//设置视频数据回调
bool SetVideoCallback(const long msHandle, videoCB* vCB, void* parameter);

//设置音频数据回调
bool SetAudioCallback(const long msHandle, audioCB* aCB, void* parameter);

//设置错误信息回调
bool SetErrorCallback(const long msHandle, errorCB* eCB, void* parameter);

//设置通道信息回调
bool SetChannelInfoCallback(const long msHandle, channelInfoCB* ciCB, void* parameter);

//实时点播
bool PlayStream(const long msHandle, const channelInfo* cIF);

//停止点播
bool StopStream(const long msHandle, const channelInfo* cIF);

