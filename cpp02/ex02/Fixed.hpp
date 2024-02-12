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
		Fixed	&operator= (const Fixed &fixed);

		bool	operator> (const Fixed &fixed) const;
		bool	operator< (const Fixed &fixed) const;
		bool	operator>= (const Fixed &fixed) const;
		bool	operator<= (const Fixed &fixed) const;
		bool	operator== (const Fixed &fixed) const;
		bool	operator!= (const Fixed &fixed) const;

		Fixed	operator+ (const Fixed &fixed) const;
		Fixed	operator- (const Fixed &fixed) const;
		Fixed	operator* (const Fixed &fixed) const;
		Fixed	operator/ (const Fixed &fixed) const;

		Fixed	&operator++ ();
		const Fixed	operator++ (int);
		Fixed	&operator-- ();
		const Fixed	operator-- (int);

		static Fixed&	min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);

		int		toInt(void) const ;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif