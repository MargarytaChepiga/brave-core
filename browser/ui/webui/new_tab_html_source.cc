/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/ui/webui/new_tab_html_source.h"

#include <string>
#include "brave/common/pref_names.h"
#include "chrome/browser/profiles/profile.h"
#include "components/grit/brave_components_resources.h"
#include "components/prefs/pref_service.h"
#include "content/public/browser/render_view_host.h"
#include "content/public/browser/web_contents.h"
#include "content/public/browser/web_ui.h"
#include "content/public/browser/web_ui_data_source.h"

namespace {

struct WebUISimpleItem {
  const char* name;
  int id;
};

void AddLocalizedStringsBulk(content::WebUIDataSource* html_source,
                             const std::vector<WebUISimpleItem>& simple_items) {
  for (size_t i = 0; i < simple_items.size(); i++) {
    html_source->AddLocalizedString(simple_items[i].name,
                                    simple_items[i].id);
  }
}

void AddResourcePaths(content::WebUIDataSource* html_source,
                      const std::vector<WebUISimpleItem>& simple_items) {
  for (size_t i = 0; i < simple_items.size(); i++) {
    html_source->AddResourcePath(simple_items[i].name,
                                 simple_items[i].id);
  }
}

}  // namespace

void CustomizeNewTabHTMLSource(content::WebUIDataSource* source) {
  std::vector<WebUISimpleItem> resources = {
    { "af7ae505a9eed503f8b8e6982036873e.woff2", IDR_BRAVE_COMMON_FONT_AWESOME_1 },
    { "fee66e712a8a08eef5805a46892932ad.woff", IDR_BRAVE_COMMON_FONT_AWESOME_2 },
    { "b06871f281fee6b241d60582ae9369b9.ttf", IDR_BRAVE_COMMON_FONT_AWESOME_3 },

    // Long list of all font possiblities we have

    // font used for headings in the new tab page
    // Other variants not added as they're under 10kb size and thus inlined by webpack
    { "282305d03e3b7232c1a4ed55ce7583a2.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_100_ITALIC_DEVANAGARI },
    { "b2f34f2b906c2a434486857b67c0c066.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_100_NORMAL_DEVANAGARI },
    { "c4c8132e6d6367c5305d4eb9f79538cc.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_200_ITALIC_DEVANAGARI },
    { "1ff8e6c958ca4fa6d8e8680f32cddd0d.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_200_NORMAL_DEVANAGARI },
    { "c838a7c27758db13e106ecfccffacff3.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_300_ITALIC_DEVANAGARI },
    { "817b30cf208868ef041477ce999af40b.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_300_NORMAL_DEVANAGARI },
    { "17d173bb066b4ac1fa10c2409b421e8e.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_400_ITALIC_DEVANAGARI },
    { "8a06c170adbf19e0dffcbe868719e6ce.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_400_NORMAL_DEVANAGARI },
    { "5fb233db2e5287e5d5bef4ad81f28ad6.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_500_ITALIC_DEVANAGARI },
    { "de652f63aa5671c535afca303c5816eb.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_500_NORMAL_DEVANAGARI },
    { "2212626fea093a7ce9ed123a8137874e.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_600_ITALIC_DEVANAGARI },
    { "b188954ed63068df7cbdd685eaf0a2b0.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_600_NORMAL_DEVANAGARI },
    { "46215b916a1eb4cb6e59d9d6de201f33.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_700_ITALIC_DEVANAGARI },
    { "84b9421628180c9167e231dedd23591a.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_700_NORMAL_DEVANAGARI },
    { "b13cb35b41cc0d5fe12000916b98d95d.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_800_ITALIC_DEVANAGARI },
    { "f2b8ee24163d55d293bd073a5258908b.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_800_NORMAL_DEVANAGARI },
    { "867d78c3a1c8f6a6ec40267b535c2ba4.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_900_ITALIC_DEVANAGARI },
    { "7899ca640abe123a9ef8329762dc54e8.woff2", IDT_BRAVE_TEXT_FONT_POPPINS_900_NORMAL_DEVANAGARI },

    // font used for text in the new tab page
    // Vietnamese variant not added as it's under 10kb size and thus inlined by webpack
    { "0e0d214cf1ebb8de4fe8f7fcf7f09274.woff2", IDR_BRAVE_TEXT_FONT_MULI_200_ITALIC_LATIN_EXT },
    { "6b2996d367c5856a42f223ae462114c0.woff2", IDR_BRAVE_TEXT_FONT_MULI_200_ITALIC_LATIN },
    { "0b0967db44ffa0dcff516f9b608cc3f9.woff2", IDR_BRAVE_TEXT_FONT_MULI_300_ITALIC_LATIN_EXT },
    { "339d6c2c5ca4b27bb76d49afb34dddf6.woff2", IDR_BRAVE_TEXT_FONT_MULI_300_ITALIC_LATIN },
    { "1559d981ccec8dc4b4feb9043271ab3d.woff2", IDR_BRAVE_TEXT_FONT_MULI_400_ITALIC_LATIN_EXT },
    { "187987e45dd0477eef7303ae467324e4.woff2", IDR_BRAVE_TEXT_FONT_MULI_400_ITALIC_LATIN },
    { "b9009a9ec1d9523408bbc5e8664d89f9.woff2", IDR_BRAVE_TEXT_FONT_MULI_600_ITALIC_LATIN_EXT },
    { "e715a720765a9f67b391874f7c741c7d.woff2", IDR_BRAVE_TEXT_FONT_MULI_600_ITALIC_LATIN },
    { "3cdef88acafd738b333bcb7b14925baa.woff2", IDR_BRAVE_TEXT_FONT_MULI_700_ITALIC_LATIN_EXT },
    { "d7fc58ebe94a8b005b6f9cb4bccaf5aa.woff2", IDR_BRAVE_TEXT_FONT_MULI_700_ITALIC_LATIN },
    { "458d41efe9564ce2f0153e0439b78ff2.woff2", IDR_BRAVE_TEXT_FONT_MULI_800_ITALIC_LATIN_EXT },
    { "cb9fe5f6a2ef4aaf7e46c9d543a91dd5.woff2", IDR_BRAVE_TEXT_FONT_MULI_800_ITALIC_LATIN },
    { "c3623463b6828827f840044c53e12db4.woff2", IDR_BRAVE_TEXT_FONT_MULI_900_ITALIC_LATIN_EXT },
    { "5e18f97c019d723846fa80f3d5bf2f46.woff2", IDR_BRAVE_TEXT_FONT_MULI_900_ITALIC_LATIN },
    { "167882d7fa8fc7cce5cdf6eb6ed20bd3.woff2", IDR_BRAVE_TEXT_FONT_MULI_200_NORMAL_LATIN_EXT },
    { "c048e5552b910480d7b7d3fcb28c69fd.woff2", IDR_BRAVE_TEXT_FONT_MULI_200_NORMAL_LATIN },
    { "a89f9444ea1b68d44f4120e250d2898f.woff2", IDR_BRAVE_TEXT_FONT_MULI_300_NORMAL_LATIN_EXT },
    { "e014ef621b16d3424c3779914b994715.woff2", IDR_BRAVE_TEXT_FONT_MULI_300_NORMAL_LATIN },
    { "7dd94f3f5749c7866546c7694980ad76.woff2", IDR_BRAVE_TEXT_FONT_MULI_400_NORMAL_LATIN_EXT },
    { "f0e1ee92a25c8246a4a1fc28b3f77084.woff2", IDR_BRAVE_TEXT_FONT_MULI_400_NORMAL_LATIN },
    { "3bef707814df0c192a19df4f31518b26.woff2", IDR_BRAVE_TEXT_FONT_MULI_600_NORMAL_LATIN_EXT },
    { "d0c20b36cf1fedcf75230805055f517b.woff2", IDR_BRAVE_TEXT_FONT_MULI_600_NORMAL_LATIN },
    { "c0cf0365a6780870d455120fcc83b425.woff2", IDR_BRAVE_TEXT_FONT_MULI_700_NORMAL_LATIN_EXT },
    { "03c3ebc1b575991ec582751b6b98e562.woff2", IDR_BRAVE_TEXT_FONT_MULI_700_NORMAL_LATIN },
    { "6d23ab5117038380fd25f70909340a87.woff2", IDR_BRAVE_TEXT_FONT_MULI_800_NORMAL_LATIN_EXT },
    { "ed853eeb06da3de8325c2a4abddc30c8.woff2", IDR_BRAVE_TEXT_FONT_MULI_800_NORMAL_LATIN },
    { "7d0f2d0b966f31e8bc75bcf6954b6b49.woff2", IDR_BRAVE_TEXT_FONT_MULI_900_NORMAL_LATIN_EXT },
    { "18a1df59976e7a18fed257368aaafa9f.woff2", IDR_BRAVE_TEXT_FONT_MULI_900_NORMAL_LATIN },

    { "img/toolbar/menu_btn.svg", IDR_BRAVE_COMMON_TOOLBAR_IMG },
    // Hash path is the MD5 of the file contents, webpack image loader does this
    { "fd85070af5114d6ac462c466e78448e4.svg", IDR_BRAVE_NEW_TAB_IMG1 },
    { "314e7529efec41c8867019815f4d8dad.svg", IDR_BRAVE_NEW_TAB_IMG4 },
    { "6c337c63662ee0ba4e57f6f8156d69ce.svg", IDR_BRAVE_NEW_TAB_IMG2 },
    { "50cc52a4f1743ea74a21da996fe44272.jpg", IDR_BRAVE_NEW_TAB_IMG14 },
    { "b6dd4b1292cfd4470e58486c56ad0832.svg", IDR_BRAVE_NEW_TAB_PRIVATE_ICON }
  };
  AddResourcePaths(source, resources);

  std::vector<WebUISimpleItem> localized_strings = {
    { "adsBlocked", IDS_BRAVE_NEW_TAB_TOTAL_ADS_BLOCKED },
    { "trackersBlocked", IDS_BRAVE_NEW_TAB_TOTAL_TRACKERS_BLOCKED },
    { "httpsUpgraded", IDS_BRAVE_NEW_TAB_TOTAL_HTTPS_UPGRADES },
    { "estimatedTimeSaved", IDS_BRAVE_NEW_TAB_TOTAL_TIME_SAVED },
    { "thumbRemoved", IDS_BRAVE_NEW_TAB_THUMB_REMOVED },
    { "undoRemoved", IDS_BRAVE_NEW_TAB_UNDO_REMOVED },
    { "restoreAll", IDS_BRAVE_NEW_TAB_RESTORE_ALL },
    { "second", IDS_BRAVE_NEW_TAB_SECOND },
    { "seconds", IDS_BRAVE_NEW_TAB_SECONDS },
    { "minute", IDS_BRAVE_NEW_TAB_MINUTE },
    { "minutes", IDS_BRAVE_NEW_TAB_MINUTES },
    { "hour", IDS_BRAVE_NEW_TAB_HOUR },
    { "hours", IDS_BRAVE_NEW_TAB_HOURS },
    { "day", IDS_BRAVE_NEW_TAB_DAY },
    { "privateNewTabTitle", IDS_BRAVE_PRIVATE_NEW_TAB_TITLE },
    { "privateNewTabDisclaimer1", IDS_BRAVE_PRIVATE_NEW_TAB_DISCLAIMER_1 },
    { "privateNewTabDisclaimer2", IDS_BRAVE_PRIVATE_NEW_TAB_DISCLAIMER_2 },
    { "duckduckGoSearchInfo", IDS_BRAVE_PRIVATE_NEW_TAB_DUCKDUCKGO_SEARCH_INFO },
    { "privateNewTabSearchLabel", IDS_BRAVE_PRIVATE_NEW_TAB_SEARCH_TOGGLE_LABEL }
  };
  AddLocalizedStringsBulk(source, localized_strings);
  }

void CustomizeNewTabWebUIProperties(content::WebUI* web_ui) {
  Profile* profile = Profile::FromWebUI(web_ui);
  PrefService* prefs = profile->GetPrefs();
  auto* web_contents = web_ui->GetWebContents();
  if (web_contents) {
    auto* render_view_host = web_contents->GetRenderViewHost();
    if (render_view_host) {
      if (web_contents->GetURL() == "chrome://newtab/") {
        render_view_host->SetWebUIProperty("adsBlockedStat", std::to_string(prefs->GetUint64(kAdsBlocked)));
        render_view_host->SetWebUIProperty("trackersBlockedStat", std::to_string(prefs->GetUint64(kTrackersBlocked)));
        render_view_host->SetWebUIProperty("javascriptBlockedStat", std::to_string(prefs->GetUint64(kJavascriptBlocked)));
        render_view_host->SetWebUIProperty("javascriptBlockedStat", std::to_string(prefs->GetUint64(kJavascriptBlocked)));
        render_view_host->SetWebUIProperty("httpsUpgradesStat", std::to_string(prefs->GetUint64(kHttpsUpgrades)));
        render_view_host->SetWebUIProperty("fingerprintingBlockedStat", std::to_string(prefs->GetUint64(kFingerprintingBlocked)));
      }
    }
  }
}
