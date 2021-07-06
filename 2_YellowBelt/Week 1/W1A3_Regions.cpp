#include <iostream>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

auto GetRank(Region region) {
    return tie(
        region.std_name,
        region.parent_std_name,
        region.names,
        region.population
    );
}

bool operator<(const Region& lhs, const Region& rhs) {
    return GetRank(lhs) < GetRank(rhs);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int max = 0;
    map<Region, int> reg2freq;
    for (const auto& region : regions) {
        max = std::max(max, ++reg2freq[region]);
    }
    return max;
}