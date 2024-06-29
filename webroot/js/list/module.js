const button = document.getElementById('modules_header')
const icon = document.getElementById('module_expand_icon')
const card = document.getElementById('modules_card')

let sys_module_mode = localStorage.getItem('system-module-mode')
sys_module_mode = setData('closed')

button.addEventListener('click', () => {
  if (sys_module_mode === 'closed') {
    sys_module_mode = setData('opened')
    icon.style.transform = 'rotate(180deg)'
    card.style.maxHeight = `${card.scrollHeight}px`

    return;
  }

  sys_module_mode = setData('closed')
  icon.style.transform = 'rotate(0deg)'
  card.style.maxHeight = null
})

function setData(mode) {
  localStorage.setItem('system-module-mode', mode)

  return localStorage.getItem('system-module-mode')
}