import React from "react";

function ConcentricCircles(props) {
  return (
    <svg
      xmlns="http://www.w3.org/2000/svg"
      width={props.diameter || "349"}
      height={props.diameter || "349"}
      fill="none"
      viewBox="0 0 349 349"
    >
      <path
        fill={props.fill || "#9BD8D3"}
        d="M174.5 349c96.373 0 174.5-78.127 174.5-174.5C349 78.126 270.873 0 174.5 0 78.126 0 0 78.126 0 174.5 0 270.873 78.126 349 174.5 349z"
        opacity="0.3"
      ></path>
      <path
        fill={props.fill || "#9BD8D3"}
        d="M174.5 312c76.492 0 138.5-61.337 138.5-137S250.992 38 174.5 38C98.009 38 36 99.337 36 175s62.009 137 138.5 137z"
        opacity="0.3"
      ></path>
      <path
        fill={props.fill || "#9BD8D3"}
        d="M174.616 283.768c60.54 0 109.616-48.524 109.616-108.384C284.232 115.525 235.156 67 174.616 67 114.077 67 65 115.525 65 175.384c0 59.86 49.077 108.384 109.616 108.384z"
        opacity="0.3"
      ></path>
    </svg>
  );
}

export default ConcentricCircles;