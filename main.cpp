#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to generate subdomains of a given domain
std::vector<std::string> generate_subdomains(const std::string& domain)
{
    // Create a vector to store the subdomains
    std::vector<std::string> subdomains;

    // Split the domain into its individual parts
    std::vector<std::string> parts = split(domain, '.');

    // Loop through the parts in reverse order
    for (int i = parts.size() - 1; i >= 0; i--)
    {
        // Create a string to hold the current subdomain
        std::string subdomain;

        // Loop through the parts from the current position to the beginning
        for (int j = i; j >= 0; j--)
        {
            // Add the current part to the subdomain
            subdomain = parts[j] + (j > 0 ? "." : "") + subdomain;
        }

        // Add the subdomain to the vector
        subdomains.push_back(subdomain);
    }

    // Return the vector of subdomains
    return subdomains;
}

// Function to split a string into a vector of substrings based on a delimiter
std::vector<std::string> split(const std::string& str, char delimiter)
{
    // Create a vector to store the substrings
    std::vector<std::string> substrings;

    // Create a string to hold the current substring
    std::string substring;

    // Loop through the characters in the string
    for (char ch : str)
    {
        // If the current character is the delimiter, add the substring to the vector
        if (ch == delimiter)
        {
            substrings.push_back(substring);
            substring.clear();
        }
        else
        {
            // Otherwise, add the character to the substring
            substring += ch;
        }
    }

    // If the string ends with the delimiter, the last substring will be empty, so we don't need to add it
    if (!substring.empty())
    {
        // Add the last substring to the vector
        substrings.push_back(substring);
    }

    // Return the vector of substrings
    return substrings;
}

// Main function
int main()
{
    // Prompt the user for a domain
    std::cout << "Enter a domain: ";

    // Read the domain from the standard input stream
    std::string domain;
    std::cin >> domain;

    // Generate the subdomains of the given domain
    std::vector<std::string> subdomains = generate_subdomains(domain);

    // Print the subdomains
    std::cout << "Subdomains:" << std::endl;
    for (const std::string& subdomain : subdomains)
    {
        std::cout << " - " << subdomain << std::endl;
    }

    // Return 0 to indicate success
    return 0;
}
