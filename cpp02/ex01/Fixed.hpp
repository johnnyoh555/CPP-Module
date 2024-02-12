#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	fixed_point;
		static const int fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int fixed_point);
		Fixed(const float fixed_point);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator= (const Fixed &fixed);

		int		toInt(void) const ;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
};

#endif