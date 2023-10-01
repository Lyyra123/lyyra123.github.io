// Lấy thẻ âm thanh bằng ID
const diceRollSound = document.getElementById('diceRollSound');
const winSound = document.getElementById('winSound');



// Hàm để phát âm thanh quay xúc xắc
function playDiceRollSound() {
    diceRollSound.play();
}

// Hàm để phát âm thanh khi người chơi chiến thắng
function playWinSound() {
    winSound.play();
}


document.addEventListener('DOMContentLoaded', function () {
    const resultHeading = document.querySelector('h1');
    const player1Dice = document.getElementById('player1Dice');
    const player2Dice = document.getElementById('player2Dice');
    const rollButton = document.getElementById('rollButton');

    // Hàm để quay xúc xắc và cập nhật hình ảnh
    function rollDice() {
        const player1RandomNumber = Math.floor(Math.random() * 6) + 1;
        const player1DiceImage = 'assets/dice' + player1RandomNumber + '.png';
        
        const player2RandomNumber = Math.floor(Math.random() * 6) + 1;
        const player2DiceImage = 'assets/dice' + player2RandomNumber + '.png';
        
        player1Dice.setAttribute('src', player1DiceImage);
        player2Dice.setAttribute('src', player2DiceImage);
        
        if (player1RandomNumber > player2RandomNumber) {
            resultHeading.innerHTML = 'Player 1 WINS';
            playWinSound();
        } else if (player1RandomNumber < player2RandomNumber) {
            resultHeading.innerHTML = 'Player 2 WINS';
            playWinSound();
        } else {
            resultHeading.innerHTML = 'DRAW';
        }
    }

    // Sự kiện click cho nút Roll
    rollButton.addEventListener('click', rollDice);
});

