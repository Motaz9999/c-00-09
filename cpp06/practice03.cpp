/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice03.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 06:52:45 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/27 07:11:06 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstddef>

void printBytes(const unsigned char *bytes, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        std::cout << std::hex << static_cast<int>(bytes[i]);
        if (i + 1 < count)
        {
            std::cout << " ";
        }
    }
    std::cout << std::dec << std::endl;
}
int main()
{
    std::cout << "--- Serializing a double into raw bytes ---" << std::endl;
    double original = 3.14159265358979;
    std::cout << "Original double: " << original << std::endl;
    // reinterpret_cast dose not convert the value the way static_cast
    //  would (that would give a rounded/truncated integer). It tells
    // the compiler to treat the SAME BITS as a different type -- here,
    // as a sequence of raw bytes rather than a floating-point number.
    unsigned char *rawBytes = reinterpret_cast<unsigned char *>(&original);
    std::cout << "Raw bytes (hex): ";
    printBytes(rawBytes, sizeof(double)); // use case
    std::cout << "\n--- Reconstructing a double from those same bytes ---" << std::endl;
    unsigned char buffer[sizeof(double)];
    for (size_t i = 0; i < sizeof(double); i++)
    {
        buffer[i] = rawBytes[i];
    }
    double *reconstructedPtr=reinterpret_cast<double*>(buffer);
    std::cout << "Reconstructed double: " << *reconstructedPtr << std::endl;
    std::cout << "Same value, recovered purely by reinterpreting the same bit" << std::endl;
    std::cout << "pattern back as a double -- no arithmetic conversion happened" << std::endl;
    std::cout << "at any point in either direction." << std::endl;
        std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}