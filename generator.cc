#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <random>

#include "config.h"

int
getRandomInteger(const int min, const int max) {
  assert(min <= max && "min must be less or equal to max");

  static const unsigned int seed = std::random_device()();
  static std::default_random_engine randomEngine(seed);

  std::uniform_int_distribution<int> uniform_dist(min, max);
  return uniform_dist(randomEngine);
}

void
printRandomNumericString(size_t len) {
  static const char characters[] = "0123456789";

  static constexpr size_t maxIndex = (sizeof(characters) - 1);

  for (size_t i = 0; i < len; ++i) {
    // Compared to printf std::putchar does not need to parse the format string
    std::putchar(characters[getRandomInteger(0, maxIndex - 1)]);
  }
}

void
printRandomDateString() {
  const int day = getRandomInteger(config::minDay, config::maxDay);
  const int month = getRandomInteger(config::minMonth, config::maxMonth);
  const int year = getRandomInteger(config::minYear, config::maxYear);

  // C-style printing is used because of the easiness of formating compared to
  // iomanip
  std::printf("%02d.%02d.%04d", day, month, year);
}

void
printRandomEmail() {
  printRandomNumericString(config::emailPrefixLength);
  std::putchar('@');

  const char *domain = config::domains[getRandomInteger(0, config::domainCount - 1)];
  std::fputs(domain, stdout);
}

void
printName(bool isMale) {
  const char **names = isMale ? config::maleNames : config::femaleNames;

  const size_t nameCount =
      isMale ? config::maleNameCount : config::femaleNameCount;

  std::fputs(names[getRandomInteger(0, nameCount - 1)], stdout);
}

void
printSurname(bool isMale) {
  const char **surnames =
      isMale ? config::maleSurnames : config::femaleSurnames;

  const size_t surnameCount =
      isMale ? config::maleSurnameCount : config::femaleSurnameCount;

  std::fputs(surnames[getRandomInteger(0, surnameCount - 1)], stdout);
}

void
printApplicant() {
  bool isMale;

  if constexpr (config::onlyHasMales) {
    isMale = true;
  } else if constexpr (config::onlyHasFemales) {
    isMale = false;
  } else {
    isMale = getRandomInteger(0, 1);
  }

  if constexpr (!config::onlyHasSurnames) {
    printName(isMale);
    std::putchar(';');
  }

  if constexpr (!config::onlyHasNames) {
    printSurname(isMale);
    std::putchar(';');
  }

  // This random numeric string represents applicant national ID
  printRandomNumericString(config::nationalIdLength);
  std::putchar(';');

  printRandomDateString();
  std::putchar(';');

  printRandomEmail();
  std::putchar(';');

  // This random numeric string represents applicant ID
  printRandomNumericString(config::applicantIdLength);
  std::putchar('\n');
}

int
main() {
  for (size_t i = 0; i < config::rowNum; ++i) {
    printApplicant();
  }

  return 0;
}