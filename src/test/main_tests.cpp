// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The ADSPLACE developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 1024750 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        /* premine in block 1 (30,001 ADS) */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 30001 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 1; nHeight < 10000; nHeight += 1) {
        /* PoW Phase One */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 250 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 10000; nHeight < 50000; nHeight += 1) {
        /* PoW Phase Two */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 225 * COIN);
        nSum += nSubsidy;
    }

    for (int nHeight = 50000; nHeight < 259200; nHeight += 1) {
        /* PoW Phase Two */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 45 * COIN);
        BOOST_CHECK(MoneyRange(nSubsidy));
        nSum += nSubsidy;
        BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);
    }
    BOOST_CHECK(nSum == 4109975100000000ULL);
}

BOOST_AUTO_TEST_SUITE_END()
