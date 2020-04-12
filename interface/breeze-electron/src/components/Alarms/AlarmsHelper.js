export function inRange(value, range) {
  if (range.min === undefined || range.max === undefined) {
    return null
  }
  return (value > range.min && value < range.max)
}
