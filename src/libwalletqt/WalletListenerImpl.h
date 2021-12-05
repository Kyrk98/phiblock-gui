// Copyright (c) 2014-2020, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MONERO_GUI_WALLETLISTENERIMPL_H
#define MONERO_GUI_WALLETLISTENERIMPL_H

#include "wallet/api/wallet2_api.h"
#include "PassphraseHelper.h"

class Wallet;

class WalletListenerImpl : public Phiblock::WalletListener, public PassphraseReceiver
{
public:
    WalletListenerImpl(Wallet * w);

    virtual void moneySpent(const std::string &txId, uint64_t amount) override;

    virtual void moneyReceived(const std::string &txId, uint64_t amount) override;

    virtual void unconfirmedMoneyReceived(const std::string &txId, uint64_t amount) override;

    virtual void newBlock(uint64_t height) override;

    virtual void updated() override;

    // called when wallet refreshed by background thread or explicitly
    virtual void refreshed() override;

    virtual void onDeviceButtonRequest(uint64_t code) override;

    virtual void onDeviceButtonPressed() override;

    virtual void onPassphraseEntered(const QString &passphrase, bool enter_on_device, bool entry_abort) override;

    virtual Phiblock::optional<std::string> onDevicePassphraseRequest(bool & on_device) override;

private:
    Wallet * m_wallet;
    PassphraseHelper m_phelper;
};

#endif //MONERO_GUI_WALLETLISTENERIMPL_H
