/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice04.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 08:43:45 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/27 08:51:03 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Simulates a legacy C-style API that takes a non-const char*, even
// though it never actually modifies the string. This kind of poorly
// const-qualified interface is extremely common in real C libraries
// written before "const correctness" was standard practice.
int legacyStrLen(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

int main()
{
    std::cout << "--- Legitimate use: interfacing with a legacy C API ---" << std::endl;
    const char *message = "Hello , legacy API!";
    // legacyStrlen(message); // would NOT compile: message is const char*,
    //                        // legacyStrlen wants char*
    // const_cast is the ONLY named cast that can remove a const
    // qualifier. We use it here because we, the caller, know for a
    // fact that legacyStrlen does not modify its argument -- we are
    // not lying to the type system, just correcting for an API that
    // was never updated to express that guarantee itself.
    int length = legacyStrLen(const_cast<char *>(message));
    std::cout << "Length via legacy API: " << length << std::endl;

    std::cout << "\n--- Illegitimate use: mutating something genuinely const ---" << std::endl;
    const int trueConst = 42;
    std::cout << "trueConst before = " << trueConst << std::endl;

    int *dangerous = const_cast<int *>(&trueConst);
    *dangerous = 100; // undefine behavior
    std::cout << "trueConst after write through dangerous = " << trueConst << std::endl;
    std::cout << "dan value " << *dangerous << std::endl;
    std::cout << "trueConst after write through dangerous = " << trueConst << std::endl;

    std::cout << "This is undefined behavior. 'trueConst' was declared genuinely" << std::endl;
    std::cout << "const -- the compiler is entitled to assume it never changes and" << std::endl;
    std::cout << "may have inlined its value elsewhere before this write happened," << std::endl;
    std::cout << "which is exactly why the printed value above may or may not" << std::endl;
    std::cout << "reflect the write at all, depending on optimization settings." << std::endl;

    return 0;
}