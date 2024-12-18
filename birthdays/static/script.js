<script>
    document.getElementById('month').addEventListener('input', function() {
        const month = parseInt(this.value);
        const dayInput = document.getElementById('day');
        let maxDays;

        switch (month) {
            case 2:  // February
                maxDays = 28;  // Assume 28, you can adjust for leap years dynamically if needed
                break;
            case 4: case 6: case 9: case 11:  // April, June, September, November
                maxDays = 30;
                break;
            default:
                maxDays = 31;
        }

        dayInput.max = maxDays;
    });
    function updateClock() {
                const clockElement = document.getElementById("clock");
                const now = new Date();
                const options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' };
                const dateStr = now.toLocaleDateString('en-US', options);
                const timeStr = now.toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit', second: '2-digit' });

                clockElement.innerHTML = `${dateStr} - ${timeStr}`;
            }

            // Update the clock every second
            setInterval(updateClock, 1000);
            // Initialize the clock immediately
            updateClock();
</script>
