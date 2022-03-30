//
// Created by Michael Lynch on 30/10/2021.
//

#pragma once

#include <SFML/System.hpp>
#include <concepts>
#include <cmath>

namespace VectorUtils
{
    template<class T>
    concept VectorType_c =
            std::same_as<T, sf::Vector2f>
            || std::same_as<T, sf::Vector2i>;

    inline auto toFloatVec(sf::Vector2i v)
    {
        return static_cast<sf::Vector2f>(v);
    }

    inline auto toIntVec(sf::Vector2f v)
    {
        return static_cast<sf::Vector2i>(v);
    }

    auto normalise(VectorType_c auto v)
    {
        float x = v.x;
        float y = v.y;

        float velocity = std::abs(x) + std::abs(y);

        return sf::Vector2f(x / velocity, y / velocity);
    }

    auto getDirectionVector(VectorType_c auto origin, VectorType_c auto target)
    {
        return normalise(target - origin);
    }

    auto velocity(auto v) -> decltype(v.x)
    {
        static_assert(VectorType_c<decltype(v)>);

        auto velocity = std::abs(v.x) + std::abs(v.y);

        return velocity;
    }

    template<VectorType_c T>
    T rotateRightAngleClockwise(T v)
    {
        return {v.y, -v.x};
    }

    auto rotateRightAngleAntiClockwise(VectorType_c auto v)
    {
        return rotateRightAngleClockwise(
                rotateRightAngleClockwise(
                        rotateRightAngleClockwise(v)));
    }

    inline sf::Vector2f rotate(sf::Vector2f v, float rotationRadians)
    {
        return sf::Vector2f {
            (v.x * std::cosf(rotationRadians)) - (v.y * std::sinf(rotationRadians)),
            (v.x * std::sinf(rotationRadians)) + (v.y * std::cosf(rotationRadians))
        };
    }

    template<typename M>
    auto multiply(VectorType_c auto v, M multiplier) -> decltype(v)
    {
        static_assert(std::is_same<decltype(v.x), M>());
        return { v.x * multiplier, v.y * multiplier};
    }

    double distance(VectorType_c auto a, VectorType_c auto b)
    {
        return std::sqrt(
                std::pow(a.x - b.x, 2)
                + std::pow(a.y - b.y, 2));
    }

    inline int manhattanDistance(sf::Vector2i a, sf::Vector2i b)
    {
        return std::abs(a.x - b.x) + std::abs(a.y - b.y);
    }

    inline sf::Vector2f roundPosition(sf::Vector2f position)
    {
        return {std::round(position.x), std::round(position.y)};
    }
};

namespace VU = VectorUtils;