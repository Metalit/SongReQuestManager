#include "Main.hpp"
#include "Settings.hpp"

DESERIALIZE_METHOD(SRM, Request,
    DESERIALIZE_CLASS(Beatmap, beatmap);
    DESERIALIZE_VALUE(Date, date, String);
    DESERIALIZE_VALUE(Requester, requester, String);
    DESERIALIZE_VALUE(NamePrefix, namePrefix, String);
    DESERIALIZE_VALUE(Message, message, String);
)

SERIALIZE_METHOD(SRM, Request,
    // SERIALIZE_CLASS(Beatmap, beatmap);
    SERIALIZE_VALUE(Date, date);
    SERIALIZE_VALUE(Requester, requester);
    SERIALIZE_VALUE(NamePrefix, namePrefix);
    SERIALIZE_VALUE(Message, message);
)

DESERIALIZE_METHOD(SRM, Database,
    DESERIALIZE_VECTOR(Queue, queue, SRM::Request);
    DESERIALIZE_VECTOR(History, history, SRM::Request);
    DESERIALIZE_VECTOR(SongBlacklist, songBlacklist, SRM::Request);
    DESERIALIZE_VECTOR_BASIC(UserBlacklist, userBlacklist, String);
    DESERIALIZE_VECTOR_BASIC(MapperBlacklist, mapperBlacklist, String);
)

SERIALIZE_METHOD(SRM, Database,
    SERIALIZE_VECTOR(Queue, queue);
    SERIALIZE_VECTOR(History, history);
    SERIALIZE_VECTOR(SongBlacklist, songBlacklist);
    SERIALIZE_VECTOR_BASIC(UserBlacklist, userBlacklist);
    SERIALIZE_VECTOR_BASIC(MapperBlacklist, mapperBlacklist);
)

DESERIALIZE_METHOD(SRM, RequestFilters,
    DESERIALIZE_VALUE(NoBeatSage, noBeatSage, Bool);
    DESERIALIZE_VALUE(NPSMin, npsMin, Bool);
    DESERIALIZE_VALUE(NPSMinV, npsMinV, Float);
    DESERIALIZE_VALUE(NPSMax, npsMax, Bool);
    DESERIALIZE_VALUE(NPSMaxV, npsMaxV, Float);
    DESERIALIZE_VALUE(NJSMin, njsMin, Bool);
    DESERIALIZE_VALUE(NJSMinV, njsMinV, Float);
    DESERIALIZE_VALUE(NJSMax, njsMax, Bool);
    DESERIALIZE_VALUE(NJSMaxV, njsMaxV, Float);
    DESERIALIZE_VALUE(DurationMax, durationMax, Bool);
    DESERIALIZE_VALUE(DurationMaxV, durationMaxV, Float);
    DESERIALIZE_VALUE(VoteMin, voteMin, Bool);
    DESERIALIZE_VALUE(VoteMinV, voteMinV, Float);
    DESERIALIZE_VALUE(DateMin, dateMin, Bool);
    DESERIALIZE_VALUE(DateMinV, dateMinV, Float);
    DESERIALIZE_VALUE(DateMax, dateMax, Bool);
    DESERIALIZE_VALUE(DateMaxV, dateMaxV, Float);
)

SERIALIZE_METHOD(SRM, RequestFilters,
    SERIALIZE_VALUE(NoBeatSage, noBeatSage);
    SERIALIZE_VALUE(NPSMin, npsMin);
    SERIALIZE_VALUE(NPSMinV, npsMinV);
    SERIALIZE_VALUE(NPSMax, npsMax);
    SERIALIZE_VALUE(NPSMaxV, npsMaxV);
    SERIALIZE_VALUE(NJSMin, njsMin);
    SERIALIZE_VALUE(NJSMinV, njsMinV);
    SERIALIZE_VALUE(NJSMax, njsMax);
    SERIALIZE_VALUE(NJSMaxV, njsMaxV);
    SERIALIZE_VALUE(DurationMax, durationMax);
    SERIALIZE_VALUE(DurationMaxV, durationMaxV);
    SERIALIZE_VALUE(VoteMin, voteMin);
    SERIALIZE_VALUE(VoteMinV, voteMinV);
    SERIALIZE_VALUE(DateMin, dateMin);
    SERIALIZE_VALUE(DateMinV, dateMinV);
    SERIALIZE_VALUE(DateMax, dateMax);
    SERIALIZE_VALUE(DateMaxV, dateMaxV);
)

DESERIALIZE_METHOD(SRM, ModConfig,
    DESERIALIZE_VALUE(UserMaxRequest, userMaxRequest, Int);
    DESERIALIZE_VALUE(VipBonusRequest, vipBonusRequest, Int);
    DESERIALIZE_VALUE(SubBonusRequest, subBonusRequest, Int);
    DESERIALIZE_VALUE(HistorySize, historySize, Int);
    DESERIALIZE_VALUE(QueueOpen, queueOpen, Bool);
    DESERIALIZE_VALUE(ModsManageQueue, modsManageQueue, Bool);
    DESERIALIZE_VALUE(QueueCmdShowCount, queueCmdShowCount, Int);
    DESERIALIZE_VALUE(QueueCmdCooldown, queueCmdCooldown, Int);
    DESERIALIZE_CLASS(Filters, filters);
)

SERIALIZE_METHOD(SRM, ModConfig,
    SERIALIZE_VALUE(UserMaxRequest, userMaxRequest);
    SERIALIZE_VALUE(VipBonusRequest, vipBonusRequest);
    SERIALIZE_VALUE(SubBonusRequest, subBonusRequest);
    SERIALIZE_VALUE(HistorySize, historySize);
    SERIALIZE_VALUE(QueueOpen, queueOpen);
    SERIALIZE_VALUE(ModsManageQueue, modsManageQueue);
    SERIALIZE_VALUE(QueueCmdShowCount, queueCmdShowCount);
    SERIALIZE_VALUE(QueueCmdCooldown, queueCmdCooldown);
    SERIALIZE_CLASS(Filters, filters);
)