function isPermutation(str1, str2) {
  var check_string = false;

  // Edge case: if str1 is longer, it cannot be a substring of str2
  if (str1.length > str2.length) return check_string;

  // Helper function to count character frequencies
  function getCountMap(str) {
    const map = {};
    for (let ch of str) map[ch] = (map[ch] || 0) + 1;
    return map;
  }

  const s1Count = getCountMap(str1);
  const windowSize = str1.length;

  for (let i = 0; i <= str2.length - windowSize; i++) {
    const window = str2.substring(i, i + windowSize);
    const s2Count = getCountMap(window);

    // Compare maps
    let isSame = true;
    for (let key in s1Count) {
      if (s1Count[key] !== s2Count[key]) {
        isSame = false;
        break;
      }
    }

    if (isSame) {
      check_string = true;
      break;
    }
  }

  return check_string;
}

// Quick tests
console.log(isPermutation("ab", "eidbaooo")); // expected: true  (because "ba" is a perm of "ab")
console.log(isPermutation("ab", "eidboaoo")); // expected: false
console.log(isPermutation("abc", "cbadef"));  // expected: true
console.log(isPermutation("a", ""));          // expected: false