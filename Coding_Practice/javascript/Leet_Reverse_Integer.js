/**
 * @param {number} x
 * @return {number}
 */


var reverse = function(x) {
    
    var xstring = x.toString();
    var result = "";

    if(xstring[0] === '-')
    {
        result += "-";
        xstring = xstring.slice(1);
    } else if(xstring[xstring.length - 1] === '0')
    {
        xstring = xstring.slice(0, xstring.length -1);
    }

    for(var i = xstring.length -1; i >= 0; i--)
    {
        result += xstring[i];
    }
    
    return result;
};


console.log(reverse(1200));
