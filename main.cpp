
#include <iostream>
#include <iomanip>
#include <locale>
#include <vector>
#include <stdexcept>

using namespace std::literals::string_literals;

static
constexpr
auto quiet { true };

int main() {
  auto lcls = std::vector<std::string> {
    "C"s,
    "POSIX"s,
    "en_US.utf8"s,
    "en_US.UTF-8"s,
    "en_GB.utf8"s,
    "en_GB.UTF-8"s,
    "en_CA.UTF-8"s,
    "en_AU.UTF-8"s,
    "en_NZ.UTF-8"s,
    "en_IE.UTF-8"s,
    "nl_NL.UTF-8"s,
    "nl_BE.UTF-8"s,
    "da_DK.UTF-8"s,
    "sv_SE.UTF-8"s,
    "no_NO.UTF-8"s,
    "fr_FR.UTF-8"s,
    "fr_BE.UTF-8"s,
    "fr_CH.UTF-8"s,
    "fr_CA.UTF-8"s,
    "de_DE.UTF-8"s,
    "de_CH.UTF-8"s,
    "it_IT.UTF-8"s,
    "it_CH.UTF-8"s,
    "pt_PT.UTF-8"s,
    "pt_BR.UTF-8"s,
    "el_GR.UTF-8"s,
    "ru_RU.UTF-8"s,
    "ja_JP.utf8"s,
    "ja_JP.UTF-8"s,
  };

  for (auto const & lcl : lcls) {
    std::cout << "Locale: "s << lcl;
    try {
      auto crnt = std::locale(lcl);
      std::cout << ", derived: "s << crnt.name() << '\n';
      std::cout.imbue(crnt);
      std::cout << std::fixed << std::showbase;
      auto mny00 = 1'000'000.918273L;
      auto mny10 = mny00 * 100.0L;
      std::cout << mny00 << ' ' << mny10 << ' '
                << std::put_money(mny10) << ' '
                << std::put_money(mny10, true)
                << '\n';
    }
    catch (std::runtime_error const & ex) {
      if (!quiet) {
        std::cout << '\n';
        std::cout << "Error: "s << ex.what() << '\n';
      }
    }
    std::cout << std::endl;
  }

  return 0;
}

// ` 1 2 3 4 5 6 7 8 9 0 - =
// ~ ! @ £ $ % ^ & * ( ) _ +
// ` ¡ € # ¢ ∞ § ¶ • ª º – ≠
// Ÿ ⁄ ™ ‹ › ﬁ ﬂ ‡ ° · ‚ — ±

