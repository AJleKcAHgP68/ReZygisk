const button = document.getElementById('settings_header')
const icon = document.getElementById('settings_expand_icon')
const card = document.getElementById('rezygisk_settings')

let sys_module_mode = localStorage.getItem('system-settings-expand-mode')
setData('closed')

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
  localStorage.setItem('system-settings-expand-mode', mode)

  return localStorage.getItem('system-settings-expand-mode')
}