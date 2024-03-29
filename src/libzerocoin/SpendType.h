// Copyright (c) 2017-2019 The PIVX developers
// Copyright (c) 2019 The ADSPLACE developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ADSPLACE_SPENDTYPE_H
#define ADSPLACE_SPENDTYPE_H

#include <cstdint>

namespace libzerocoin {
    enum SpendType : uint8_t {
        SPEND, // Used for a typical spend transaction, zADS should be unusable after
        STAKE, // Used for a spend that occurs as a stake
        MN_COLLATERAL, // Used when proving ownership of zADS that will be used for masternodes (future)
        SIGN_MESSAGE // Used to sign messages that do not belong above (future)
    };
}

#endif //ADSPLACE_SPENDTYPE_H
